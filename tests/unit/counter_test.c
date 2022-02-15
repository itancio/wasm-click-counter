#include "utest.h"
#include "../../src/counter.h"

struct TestFixture {
    struct Counter counter;
};

UTEST_F_SETUP(TestFixture) {
    utest_fixture->counter.count = 0;
}
UTEST_F_TEARDOWN(TestFixture) {}

UTEST_F(TestFixture, should_start_at_0) {
    struct Counter c = utest_fixture->counter;
    ASSERT_EQ(c.count, 0);
}

UTEST_F(TestFixture, should_increment_to_1) {
    struct Counter c = utest_fixture->counter;
    counter_inc(&c);
    ASSERT_EQ(c.count, 1);
}

UTEST_MAIN()
