add_custom_command(
    OUTPUT sentry_generated.h
    COMMAND ../../flatbuffers/flatc --cpp sentry.fbs
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
add_custom_target(gen_sentry_format DEPENDS sentry_generated.h)
add_dependencies(side gen_sentry_format)