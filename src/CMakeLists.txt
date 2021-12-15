target_sources(side PRIVATE
    "main.cpp"
    "editor.cpp"
    "render_host.cpp"
    "init.cpp"
)
# Add Cross-System filesystem
add_subdirectory(csfs)