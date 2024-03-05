# Indicator Home Assistant Light Control Demo

This demo is mainly based on the indicator_basis demo with added Home Assistant functions.

<figure class="third">

</figure>

## Function
- [x] Time display.
- [x] CO2, tVOC, Temperature and Humidity data real-time display.
- [x] CO2, tVOC, Temperature and Humidity history data display.
- [x] Wifi config.
- [x] Display config.
- [x] time config.
- [x] Home Assistant control.

## How to use example

Please first read the [User Guide](https://wiki.seeedstudio.com/SenseCAP_Indicator_Get_Started) of the SenseCAP Indicator Board to learn about its software and hardware information.


Here are some simple steps to use.

- Step 1: Clone to local
- Step 2: Modify the HA token and entity id in ./main/controller/indicator_controller_ha.c 
- Step 3: Build and lash the project
- Step 4: Open github and give my project a star.
- 
Add the following to the raw configuration editor of the dashboard.


### Build and Flash

1. The project configure PSRAM with Octal 120M by default. please see [here](../../tools/patch/README.md#idf-patch) to enable `PSRAM Octal 120M` feature.
2. Run `idf.py -p PORT flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.
