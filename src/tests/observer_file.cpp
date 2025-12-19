#include "observer_file.hpp"

#include "gtest/gtest.h"
#include <fstream>
#include <filesystem>

TEST(FileLoggerTest, WritesToFile) {
    FileLogger logger;
    
    std::remove("log.txt");
    
    logger.onEvent("Test log entry 1");
    logger.onEvent("Test log entry 2");
    
    std::ifstream file("log.txt");
    ASSERT_TRUE(file.is_open());
    
    std::string line;
    std::getline(file, line);
    EXPECT_EQ(line, "Test log entry 1");
    
    std::getline(file, line);
    EXPECT_EQ(line, "Test log entry 2");
    
    file.close();
    std::remove("log.txt");
}