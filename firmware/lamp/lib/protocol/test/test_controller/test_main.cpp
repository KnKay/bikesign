#include <unity.h>
#include "controller.h"
#include "fake_output.h"
#include "protocol.h"

bikelamp::protocol::BasicController dut;
fakes::fakeOutput left;
fakes::fakeOutput right;
fakes::fakeOutput brake;
fakes::fakeOutput lamp;

void setUp(void){
    dut.turn_left = &left;
    dut.turn_right = &right;
    dut.brake = &brake;
    dut.lamps = &lamp;
}

void test_left(){
    TEST_ASSERT(!left.state);
    bikelamp::protocol::Command command;
    command.order = bikelamp::protocol::Order::ON;
    command.output = bikelamp::protocol::Output::LEFT;
    dut.handle(command);
    TEST_ASSERT(left.state);
}

void test_right(){
    TEST_ASSERT(!right.state);
    bikelamp::protocol::Command command;
    command.order = bikelamp::protocol::Order::ON;
    command.output = bikelamp::protocol::Output::RIGHT;
    dut.handle(command);
    TEST_ASSERT(right.state);
}

void RUN_UNITY_TESTS() {
    UNITY_BEGIN();
    RUN_TEST(test_left);
    RUN_TEST(test_right);
    UNITY_END();
}

int main(int argc, char **argv) {
    RUN_UNITY_TESTS();
    return 0;
}
