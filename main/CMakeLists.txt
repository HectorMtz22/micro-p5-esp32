idf_component_register(
    SRCS "main.c"
    PRIV_REQUIRES esp_driver_gpio 
    INCLUDE_DIRS "."
    REQUIRES Display7Seg
    REQUIRES Buttons 
    REQUIRES Ledc
)
