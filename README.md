# ReMu
Reharmonization of Music notation through the use of a DSL

## Dependencies

- Musescore3: https://musescore.org/en/download
- QT5: https://www.qt.io/download

## Compilation

### Command Line Interface

To compile ReMu,first, open the Visual Studio solution and build the CLI project. This can be used in isolation as the command line interface or paired with the GUI.

### GUI

To compile the GUI the QT5 version needs to be attached to the GUIx86 project. Next, build the project and run it. Before you can use the software MuseScore and the CLI need to be configured. Go to the settings menu in ReMu and select "Configure", here write the absolute path to both MuseScore3.exe and CLI.exe.
