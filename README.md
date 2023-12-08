# Flight Management System

## How to Run

1. Open the integrated terminal within the project.
2. Run the command:
    ```
    g++ main.cpp seat.cpp passenger.cpp passengerlist.cpp flight.cpp airline.cpp
    ```
3. Execute the generated executable to start the program.

## Key Features

The `main.cpp` file orchestrates the entire flight management program, encompassing various functionalities:

- **Menu Functionality:** Presents a menu with options to:
  - View seat maps
  - Display passenger information
  - Add or remove passengers
  - Save data
  - Quit the program

- **Populating Flight Information:** Reads data from `flight_info.txt` to populate flight details, including flight number, maximum rows, columns, and passenger information.

- **Displaying Seat Map:** Shows the graphical representation of the flight's seat arrangement.

- **Displaying Passenger Information:** Presents comprehensive details about passengers aboard the flight.

- **Adding Passengers:** Facilitates the addition of new passengers, ensuring validation of IDs, names, phone numbers, desired rows, and seats.

- **Removing Passengers:** Allows the removal of passengers by their unique ID from the flight manifest.
