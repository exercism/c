#include "test-framework/unity.h"
#include "pacman_rules.h"

void setUp(void)
{
}

void tearDown(void)
{
}

// task 1
static void check_touching_no_power_pellet(void)
{
    TEST_ASSERT(!can_eat_ghost(false, true));
}

static void check_not_touching_ghost(void)
{
    TEST_ASSERT(!can_eat_ghost(false, true));
}

static void check_not_touching_no_power_pellet(void)
{
    TEST_ASSERT(!can_eat_ghost(false, false));
}

// task 2
static void check_eating_dot(void)
{
    TEST_ASSERT(scored(false, true));
}

static void check_eating_power_pellet(void)
{
    TEST_ASSERT(scored(true, false));
}

static void check_nothing_eaten(void)
{
    TEST_ASSERT(!scored(false, false));
}

// task 3
static void check_touching_ghost_no_power_pellet(void)
{
    TEST_ASSERT(lost(false, true));
}

static void check_touching_ghost_with_power_pellet(void)
{
    TEST_ASSERT(!lost(true, true));
}

static void check_not_touching_ghost_with_power_pellet(void)
{
    TEST_ASSERT(!lost(true, false));
}

// task 4
static void check_win_all_dots_eaten(void)
{
    TEST_ASSERT(won(true, false, false));
}

static void check_no_win_all_dots_eaten_but_touching_ghost(void)
{
    TEST_ASSERT(!won(true, false, true));
}

static void check_win_all_dots_eaten_touching_ghost_with_power_pellet(void)
{
    TEST_ASSERT(won(true, true, true));
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(check_touching_no_power_pellet);
    RUN_TEST(check_not_touching_ghost);
    RUN_TEST(check_not_touching_no_power_pellet);
    RUN_TEST(check_eating_dot);
    RUN_TEST(check_eating_power_pellet);
    RUN_TEST(check_nothing_eaten);
    RUN_TEST(check_touching_ghost_no_power_pellet);
    RUN_TEST(check_touching_ghost_with_power_pellet);
    RUN_TEST(check_not_touching_ghost_with_power_pellet);
    RUN_TEST(check_win_all_dots_eaten);
    RUN_TEST(check_no_win_all_dots_eaten_but_touching_ghost);
    RUN_TEST(check_win_all_dots_eaten_touching_ghost_with_power_pellet);

   return UNITY_END();
}
