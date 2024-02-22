/*
** EPITECH PROJECT, 2024
** pipunit
** File description:
** main
*/

#include <iostream>
#include <vector>
#include "src/Assertion.hpp"
#include "src/Test.hpp"

Assertion test_assert_equals(
    pipunit::CoutRedirect *cout,
    pipunit::CerrRedirect *cerr
)
{
    (void)cout;
    (void)cerr;
    return assert_equals(1, 1);
}

Assertion test_assert_stdout(
    pipunit::CoutRedirect *cout,
    pipunit::CerrRedirect *cerr
)
{
    (void)cerr;
    std::cout << "Hello World" << std::endl;
    return assert_stdout_equals(cout, "Hello World\n");
}

Assertion test_assert_stderr(
    pipunit::CoutRedirect *cout,
    pipunit::CerrRedirect *cerr
)
{
    (void)cout;
    std::cerr << "Hello World" << std::endl;
    return assert_stderr_equals(cerr, "Hello World\n");
}

int main(void)
{
    std::vector<pipunit::Test> suite;

    suite.push_back(pipunit::Test(
        "test_assert_equals",
        "test_assert_equals",
        test_assert_equals,
        NULL,
        NULL
    ));
    suite.push_back(pipunit::Test(
        "test_assert_stdout",
        "test_assert_stdout",
        test_assert_stdout,
        pipunit::redirectStdout,
        NULL
    ));
    suite.push_back(pipunit::Test(
        "test_assert_stderr",
        "test_assert_stderr",
        test_assert_stderr,
        NULL,
        pipunit::redirectStderr
    ));
    suite.push_back(pipunit::Test("empty test", "empty", NULL, NULL, NULL));
    pipunit::printResult(suite);
    return 0;
}
