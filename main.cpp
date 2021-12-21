#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>

#include "include/AppStarter.h"

int main() {
    AppStarter app;
    app.start();
    return 0;
}

/*
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
