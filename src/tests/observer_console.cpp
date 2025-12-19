#include "observer_console.hpp"

#include "gtest/gtest.h"
#include <sstream>

TEST(ConsoleLoggerTest, OutputsMessage) {
    ConsoleLogger logger;
    
    std::ostringstream output;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(output.rdbuf());
    
    logger.onEvent("Test message");
    
    std::cout.rdbuf(oldCout);
    
    EXPECT_EQ(output.str(), "Test message\n");
}