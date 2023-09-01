# PhoneBook

---

PhoneBook is a simple CLI Contact app developed as a University project. It provides basic functionality for managing a contact list stored in a text database. This README will guide you through building and using the application.

## Build

To build the PhoneBook application, you can use a C++ compiler such as g++. Here are the steps to build it:

```sh
/path/to/g++ -g Helper.cpp DisplayController.cpp main.cpp -o PhoneBook
```

If you don't have a C++ compiler installed, you can also run the precompiled executable "PhoneBook.exe" if available.

## Features and Concepts

### Controllers and Encapsulation

The PhoneBook application follows a modular structure with controllers that encapsulate different aspects of the functionality. This promotes code organization and maintainability.

### Single Responsibility Principle

Each component within the application adheres to the single responsibility principle, ensuring that every class or module has a specific, well-defined purpose.

### Header Files and Reusable Methods

The use of header files and modular design allows for the creation of reusable methods and functions, promoting code reusability and readability.

### Static Methods

Static methods are employed where appropriate to encapsulate behavior that does not require instance-specific data. This helps in efficiently organizing and accessing certain functionalities.

### Storing Contacts Data in Text File
PhoneBook stores contacts data in a text file, providing a simple and portable way to maintain your contacts list. This text-based database ensures that your contacts are easily accessible and can be backed up or transferred as needed.

### Version Control System and GitHub Repository

The project is maintained using a version control system, likely Git, and hosted on a GitHub repository. This allows for easy collaboration, version tracking, and code sharing.

## Usage

Once you have built or obtained the executable, you can run PhoneBook from your terminal or command prompt. The application will provide you with options to manage your contacts, such as adding new contacts, searching for contacts, updating contact information, and deleting contacts.
