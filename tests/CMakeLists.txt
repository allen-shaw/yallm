# Find test framework
find_package(GTest REQUIRED)

# Add test executable
add_executable(yallm_tests
  main_test.cc
)

target_link_libraries(yallm_tests
  PRIVATE
  yallm_lib
  GTest::GTest
  GTest::Main
)

# Add tests to CTest
add_test(NAME yallm_tests COMMAND yallm_tests)
