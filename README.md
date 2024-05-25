# CLICKED RANDOM APP

## Description

CLICKED RANDOM APP is a simple SDL-based application that demonstrates interactive buttons and mouse event handling. When the button is clicked, its position is randomized within the window, providing a simple interactive experience.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Introduction

This application showcases how to create a graphical user interface using SDL (Simple DirectMedia Layer) library in C. It provides a button that changes its position randomly within the window when clicked. Additionally, it displays mouse coordinates and instructions for interaction.

### Features

- Interactive button with click event handling
- Randomized button position on click
- Display of mouse coordinates
- Simple user interface with clear instructions

## Installation

To run CLICKED RANDOM APP on your system, follow these steps:

1. Clone the repository:

    ```bash
    git clone https://github.com/your_username/your_project.git
    ```

2. Install SDL library:

    - On Debian/Ubuntu:

        ```bash
        sudo apt-get install libsdl2-dev libsdl2-ttf-dev
        ```

    - On macOS (using Homebrew):

        ```bash
        brew install sdl2 sdl2_ttf
        ```

    - On Windows:

        Download SDL2 development libraries from the [official SDL website](https://www.libsdl.org/download-2.0.php) and follow the installation instructions.

3. Compile the program:

    ```bash
    gcc -o clicked_random_app clicked_random_app.c `sdl2-config --cflags --libs` -lSDL2_ttf
    ```

4. Run the executable:

    ```bash
    ./clicked_random_app
    ```

## Usage

Once the application is running, you'll see a button labeled "Click me" inside a rectangle. Clicking on the button will randomize its position within the window. The mouse coordinates are displayed at the bottom of the window, and instructions are provided for interaction.

## Contributing

Contributions to CLICKED RANDOM APP are welcome! If you'd like to contribute, please follow these guidelines:

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/new-feature`
3. Make your changes and commit them: `git commit -m 'Add new feature'`
4. Push to the branch: `git push origin feature/new-feature`
5. Submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Contact

If you have any questions or suggestions regarding CLICKED RANDOM APP, feel free to contact the project maintainer:

- [GitHub](https://github.com/your_username)
- Email: asfandyarkhan.dev@gmail.com
