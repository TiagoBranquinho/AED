#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <iostream>

#include "include/App.h"

int main() {
    App application = App();
    application.start();
    return 0;
}

/*
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}*/
