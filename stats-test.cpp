#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include "stats.h"

#include <math.h>

TEST_CASE("reports average, minimum and maximum") {
    float numberset[] = {22.5,55.5,66.6,20.2,2};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    stats_s computedStats = {0,0,0};
    computedStats = compute_statistics(numberset, setlength);
    float epsilon = 0.001;
    REQUIRE(abs(computedStats.average - 4.525) < epsilon);
    REQUIRE(abs(computedStats.max - 8.9) < epsilon);
    REQUIRE(abs(computedStats.min - 1.5) < epsilon);
}


TEST_CASE("average is NaN for empty array") {
    int setlength = 0;
    float numberset[] = {1.5, 8.9, 3.2, 4.5};
    stats_s computedStats;
    computedStats = compute_statistics(numberset, setlength);
    
    REQUIRE(isnan(computedStats.average) == TRUE);
}

TEST_CASE("do not raises alerts when max is lesser than threshold") {
    alerter_funcptr alerters[] = {emailAlerter, ledAlerter};

    float numberset[] = {11,55.5,46.6,8.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    stats_s computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 100.2;
    check_and_alert(maxThreshold, alerters, computedStats);

    // need a way to check if both emailAlerter, ledAlerter were called
    // you can define call-counters along with the functions, as shown below
    REQUIRE(emailAlertCallCount == 0);
    REQUIRE(ledAlertCallCount == 0);
}

TEST_CASE("raises alerts when max is greater than threshold") {
    alerter_funcptr alerters[] = {emailAlerter, ledAlerter};

    float numberset[] = {99.8, 34.2, 4.5};
    int setlength = sizeof(numberset) / sizeof(numberset[0]);
    stats_s computedStats = compute_statistics(numberset, setlength);

    const float maxThreshold = 10.2;
    check_and_alert(maxThreshold, alerters, computedStats);

    // need a way to check if both emailAlerter, ledAlerter were called
    // you can define call-counters along with the functions, as shown below
    REQUIRE(emailAlertCallCount == 1);
    REQUIRE(ledAlertCallCount == 1);
}
