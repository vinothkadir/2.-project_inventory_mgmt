#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm> // Include algorithm header for std::find_if

class Order {
private:
    int order_id;
    int product_id;
    int quantity_ordered;
    std::chrono::system_clock::time_point order_date;
    std::string status;
public:
    Order(int product_id, int quantity_ordered)
        : product_id(product_id), quantity_ordered(quantity_ordered), status("pending") {
        order_date = std::chrono::system_clock::now();
    }

    void set_order_id(int id) {
        order_id = id;
    }

    int get_order_id() const { // Ensure const correctness
        return order_id;
    }

    int get_product_id() const { // Ensure const correctness
        return product_id;
    }

    std::string get_status() const { // Ensure const correctness
        return status;
    }
};

class Product {
private:
    int product_id;
    std::string name;
    std::string description;
    double price;
    int quantity_in_stock;
    int reorder_level;
public:
    Product(int product_id, std::string name, std::string description, double price, int quantity_in_stock, int reorder_level)
        : product_id(product_id), name(name), description(description), price(price), quantity_in_stock(quantity_in_stock), reorder_level(reorder_level) {}

    Order* reorder(int quantity_ordered) const { // Ensure const correctness
        if (quantity_in_stock < reorder_level) {
            std::cout << "Placing an order for Product ID " << product_id << "..." << std::endl;
            return new Order(product_id, quantity_ordered);
        }
        return nullptr;
    }

    int get_product_id() const { // Ensure const correctness
        return product_id;
    }
};

class Supplier {
private:
    int supplier_id;
    std::string name;
    std::string contact_info;
public:
    Supplier(int supplier_id, std::string name, std::string contact_info)
        : supplier_id(supplier_id), name(name), contact_info(contact_info) {}
};

class InventorySystem {
private:
    std::vector<Product> products;
    std::vector<Supplier> suppliers;
    std::vector<Order*> orders;
    int product_id_counter;
    int supplier_id_counter;
    int order_id_counter;
public:
    InventorySystem()
        : product_id_counter(1), supplier_id_counter(1), order_id_counter(1) {}

    void add_product(std::string name, std::string description, double price, int quantity_in_stock, int reorder_level) {
        Product product(product_id_counter++, name, description, price, quantity_in_stock, reorder_level);
        products.push_back(product);
    }

    void add_supplier(std::string name, std::string contact_info) {
        Supplier supplier(supplier_id_counter++, name, contact_info);
        suppliers.push_back(supplier);
    }

    void place_order(int product_id, int quantity_ordered) {
        auto it = std::find_if(products.begin(), products.end(), [=](const Product& p) { // Use std::find_if
            return p.get_product_id() == product_id;
        });
        if (it != products.end()) {
            Order* order = it->reorder(quantity_ordered);
            if (order) {
                order->set_order_id(order_id_counter++);
                orders.push_back(order);
                std::cout << "Order placed and Order id is: " << order->get_order_id() << std::endl;
            } else {
                std::cout << "Product does not require reordering." << std::endl;
            }
        } else {
            std::cout << "Product with ID " << product_id << " not found." << std::endl;
        }
    }

    void list_orders() const { // Ensure const correctness
        for (const auto& order : orders) {
            std::cout << "Order id: " << order->get_order_id() << ", Product id: " << order->get_product_id() << ", Status: " << order->get_status() << std::endl;
        }
    }
};

int main() {
    InventorySystem inventory_system;

    inventory_system.add_product("laptop", "high-performance laptop", 999.99, 10, 5);
    inventory_system.add_product("phone", "smartphone", 499.99, 20, 10);
    inventory_system.add_supplier("tech Supplier", "techsuppliers@example.com");

    inventory_system.place_order(1, 5);
    inventory_system.place_order(2, 15);

    inventory_system.list_orders();

    return 0;
}
