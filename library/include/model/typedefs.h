#ifndef SELFPROTECTIONSHOP_TYPEDEFS_H
#define SELFPROTECTIONSHOP_TYPEDEFS_H
#include <functional>
#include <memory>


class Client;
class ClientAddress;
class ShippingAddress;
class Product;
class Nightstick;
class Taser;
class PepperSpray;
class ClientRepository;
class ProductRepository;
class OrderRepository;
class ShoppingCart;
class Order;
class ClientManager;
class ProductManager;
class OrderManager;


typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientAddress> ClientAddressPtr;
typedef std::shared_ptr<ShippingAddress> ShippingAddressPtr;
typedef std::shared_ptr<Product> ProductPtr;
typedef std::shared_ptr<Nightstick> NightstickPtr;
typedef std::shared_ptr<Taser> TaserPtr;
typedef std::shared_ptr<PepperSpray> PepperSprayPtr;
typedef std::shared_ptr<Order> OrderPtr;
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef std::shared_ptr<ProductRepository> ProductRepositoryPtr;
typedef std::shared_ptr<OrderRepository> OrderRepositoryPtr;
typedef std::shared_ptr<ClientManager> ClientManagerPtr;
typedef std::shared_ptr<ProductManager> ProductManagerPtr;
typedef std::shared_ptr<OrderManager> OrderManagerPtr;
typedef std::shared_ptr<ShoppingCart> ShoppingCartPtr;
typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(ProductPtr)> ProductPredicate;
typedef std::function<bool(OrderPtr)> OrderPredicate;


#endif //SELFPROTECTIONSHOP_TYPEDEFS_H
