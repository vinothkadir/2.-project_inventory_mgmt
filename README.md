# project_inventory_mgmt

Project Title: Inventory Management System

Project Description: Implemented a console-based inventory management system in C++ to track products, suppliers, and orders within a warehouse or retail environment.

Technologies Used:

C++
Standard Template Library (STL)
Chrono library for handling date and time
Key Features:

Created classes for Product, Supplier, Order, and InventorySystem to model products, suppliers, orders, and the inventory management system.
Products can be added to the inventory system with details such as name, description, price, quantity in stock, and reorder level.
Suppliers can be added to the system with contact information.
Orders can be placed for products when the quantity in stock falls below a specified reorder level.
Orders are tracked with unique order IDs and can be listed to monitor their status.

Contribution:

Developed the Product, Supplier, Order, and InventorySystem classes, including functionalities for adding products and suppliers, placing orders, and listing orders.
Ensured proper encapsulation and const correctness in class member functions.

Challenges and Solutions:

Implementing a robust system for tracking orders and managing inventory levels efficiently.
Solution: Utilized the Standard Template Library (STL) algorithms like std::find_if for searching products and implemented logic to determine when orders should be placed.

Results or Impact:

Created a functional inventory management system that helps streamline the process of tracking products, managing inventory levels, and placing orders for restocking.

Future Enhancements:

Implement additional features such as user authentication, graphical user interface (GUI), and advanced reporting functionalities for better inventory management.

Time Complexity:

1. Adding a product/supplier: O(1)
2. Placing an order: O(n) where n is the number of products
3. Listing orders: O(m) where m is the number of orders
   
Space Complexity:

1. Adding a product/supplier: O(1)
2. Placing an order: O(1)
3. Listing orders: O(m) where m is the number of orders
