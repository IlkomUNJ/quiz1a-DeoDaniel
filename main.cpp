#include <iostream>
#include "bank_customer.h"
#include "buyer.h"
#include <vector>
using namespace std;

// Minimal Seller class for demonstration
class Seller {
private:
    int id;
    string name;
public:
    Seller(int id, const string& name) : id(id), name(name) {}
    string getName() const { return name; }
    int getId() const { return id; }
};

enum PrimaryPrompt{LOGIN, REGISTER, EXIT, ADMIN_LOGIN};
enum RegisterPrompt{CREATE_BUYER, CREATE_SELLER, BACK};

int main() {
    //create a loop prompt 
    PrimaryPrompt prompt = LOGIN;
    RegisterPrompt regPrompt = CREATE_BUYER;
    const string ADMIN_USERNAME = "root";
    const string ADMIN_PASSWORD = "toor";
    string username, password;
    bool admin_status = false;

    // Demo data for buyers
    vector<BankCustomer> buyers = {
        BankCustomer(1, "Alice", 1000.0),
        BankCustomer(2, "Bob", 500.0),
        BankCustomer(3, "Charlie", 750.0)
    };

    // Demo data for sellers
    vector<Seller> sellers = {
        Seller(1, "AppleStore"),
        Seller(2, "Alfamart"),
        Seller(3, "JodieStore")
    };

    while (prompt != EXIT) {
        cout << "Select an option: " << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
        cout << "4. Admin Login" << endl;
        int choice;
        cin >> choice;
        prompt = static_cast<PrimaryPrompt>(choice - 1);
        switch (prompt) {
            case LOGIN:
                cout << "Login selected." << endl;
                /* if Login is selected, based on authority then provide options:
                assume user is logged in as Buyer for now
                1. Chek Account Status (will display if user is Buyer or Seller or both and linked banking account status)
                Will display Buyer, Seller and Banking Account details
                2. Upgrade Account to Seller
                Will prompt user to enter Seller details and create a Seller account linked to Buyer account
                Will reject if a user dont have a banking account linked
                3. Create Banking Account (if not already linked), will be replaced with banking functions
                Must provides: initial deposit amount, Address, Phone number, Email
                Banking functions will provides: Balance checking, Transaction History, Deposit, Withdraw
                4. Browse Store Functionality
                Will display all stores initially
                Need to select a store to browse each store inventory
                Will display all items in the store inventory
                After selecting an item, will display item details and option to add to cart
                After adding to cart, will notify user item is added to cart
                5. Order Functionality
                Will display all items in cart
                Will provide option to remove item from cart
                Will provide option to checkout
                After checkout invoide will be generated (will go to payment functionality)
                6. Payment Functionality
                Will display all listed invoices
                Pick an invoice to pay
                Will display invoice details and total amount
                Will provide option to pay invoice
                Payment is done through confirmation dialogue
                In confirmation dialogue, will display account balance as precursor
                User will need to manually enter invoice id to pay
                After paying balance will be redacted from buyer and added to the responding seller account
                After payment, order status will be changed to paid
                7. Logout (return to main menu)
                Display confirmation dialogue
                If confirmed, return to main menu
                If not, return to Buyer menu
                8. Delete Account (remove both Buyer and Seller account and relevant banking account)
                Display confirmation dialogue
                If confirmed, delete account and return to main menu
                If not, return to Buyer menu

                assume user is logged in as Seller for now
                9. Check Inventory
                10. Add Item to Inventory
                11. Remove Item from Inventory
                12. View Orders (will display all orders placed to this seller
                Only orders with paid status will be listed
                Order details will listing items, quantity, total amount, buyer details, order status (paid, cancelled, completed)
                extra functions
                9. Exit to main Menu
                10. Exit Program
                **/
                break;
            case REGISTER:
                regPrompt = CREATE_BUYER; // reset regPrompt to CREATE_BUYER when entering register menu
                while (regPrompt != BACK){
                    cout << "Register selected. " << endl;
                    cout << "Select an option: " << endl;
                    cout << "1. Create Buyer Account" << endl;
                    cout << "2. Create Seller Account" << endl;
                    cout << "3. Back" << endl;
                    int regChoice;
                    cin >> regChoice;
                    regPrompt = static_cast<RegisterPrompt>(regChoice - 1);
                    switch (regPrompt) {
                        case CREATE_BUYER:
                            cout << "Create Buyer Account selected." << endl;
                            break;
                        case CREATE_SELLER:
                            cout << "Create Seller Account selected." << endl;
                            break;
                        case BACK:
                            cout << "Back selected." << endl;
                            break;
                        default:
                            cout << "Invalid option." << endl;
                            break;
                    }
                }
                /* if register is selected then went throuhh registration process:
                1. Create a new Buyer Account
                Must provides: Name, Home Address, Phone number, Email
                2. Option to create a Seller Account (will be linked to Buyer account)
                Must Provides 1: Home Address, Phone number, Email
                Must provides 2: Store Name, Store Address, Store Phone number, Store Email
                Must provides 3: initial deposit amount
                After finished immediately logged in as Buyer/Seller
                */
                break;
            case EXIT:
                cout << "Exiting." << endl;
                break;
            case ADMIN_LOGIN:
                /* Prompt for username & password then check the entries with our hard coded features */
                cout << "Username: ";
                cin >> username;
                cout << "Password: ";
                cin >> password;
                if (username == ADMIN_USERNAME && password == ADMIN_PASSWORD) {
                    cout << "Admin login successful." << endl;
                    prompt = ADMIN_LOGIN;
                    admin_status = true;

                    // Admin sub-menu
                    bool adminMenu = true;
                    while (adminMenu) {
                        cout << "\nAdmin Menu:" << endl;
                        cout << "1. Account Management" << endl;
                        cout << "2. System Report" << endl;
                        cout << "3. Logout" << endl;
                        int adminChoice;
                        cin >> adminChoice;
                        switch (adminChoice) {
                            case 1: {
                                bool accountMgmt = true;
                                while (accountMgmt) {
                                    cout << "\nAccount Management:" << endl;
                                    cout << "1. View All Buyers" << endl;
                                    cout << "2. View All Sellers" << endl;
                                    cout << "3. View Buyer/Seller Details" << endl;
                                    cout << "4. Search Buyer/Seller" << endl;
                                    cout << "5. Create Buyer/Seller/Bank Account" << endl;
                                    cout << "6. Remove Buyer/Seller by ID" << endl;
                                    cout << "7. Back" << endl;
                                    int accChoice;
                                    // Move these outside the switch to avoid jump errors
                                    int searchType = 0, searchField = 0, createType = 0, removeType = 0;
                                    int bid = 0, sid = 0, searchId = 0;
                                    int detailType = 0; // <-- Add this line to declare detailType
                                    string searchName, name;
                                    bool found = false;
                                    char confirm;
                                    while (accountMgmt) {
                                        cout << "\nAccount Management:" << endl;
                                        cout << "1. View All Buyers" << endl;
                                        cout << "2. View All Sellers" << endl;
                                        cout << "3. View Buyer/Seller Details" << endl;
                                        cout << "4. Search Buyer/Seller" << endl;
                                        cout << "5. Create Buyer/Seller/Bank Account" << endl;
                                        cout << "6. Remove Buyer/Seller by ID" << endl;
                                        cout << "7. Back" << endl;
                                        cin >> accChoice;
                                        cin.ignore(); // Always ignore newline after int input
                                        switch (accChoice) {
                                            case 1:
                                                cout << "All Buyers:" << endl;
                                                for (const auto& buyer : buyers) {
                                                    cout << "- " << buyer.getName() << endl;
                                                }
                                                break;
                                            case 2:
                                                cout << "All Sellers:" << endl;
                                                for (const auto& seller : sellers) {
                                                    cout << "- " << seller.getName() << endl;
                                                }
                                                break;
                                            case 3:
                                                cout << "View Details for (1) Buyer or (2) Seller? ";
                                                cin >> detailType;
                                                cin.ignore();
                                                if (detailType == 1) {
                                                    cout << "Enter Buyer ID: ";
                                                    cin >> bid;
                                                    cin.ignore();
                                                    found = false;
                                                    for (const auto& buyer : buyers) {
                                                        if (buyer.getId() == bid) {
                                                            buyer.printInfo();
                                                            found = true;
                                                            break;
                                                        }
                                                    }
                                                    if (!found) cout << "Buyer not found." << endl;
                                                } else if (detailType == 2) {
                                                    cout << "Enter Seller ID: ";
                                                    cin >> sid;
                                                    cin.ignore();
                                                    found = false;
                                                    for (const auto& seller : sellers) {
                                                        if (seller.getId() == sid) {
                                                            cout << "Seller ID: " << seller.getId() << endl;
                                                            cout << "Seller Name: " << seller.getName() << endl;
                                                            // Add more seller details here if needed
                                                            found = true;
                                                            break;
                                                        }
                                                    }
                                                    if (!found) cout << "Seller not found." << endl;
                                                } else {
                                                    cout << "Invalid type." << endl;
                                                }
                                                break;
                                            case 4:
                                                cout << "Search for (1) Buyer or (2) Seller? ";
                                                cin >> searchType;
                                                cout << "Search by: 1. Name  2. Account ID  3. Address  4. Phone Number" << endl;
                                                cout << "Enter option: ";
                                                cin >> searchField;
                                                cin.ignore();
                                                found = false;
                                                if (searchType == 1) {
                                                    // Buyer search
                                                    if (searchField == 1) {
                                                        cout << "Enter name to search: ";
                                                        getline(cin, searchName);
                                                        for (const auto& buyer : buyers) {
                                                            if (buyer.getName() == searchName) {
                                                                cout << "[Buyer]" << endl;
                                                                buyer.printInfo();
                                                                found = true;
                                                            }
                                                        }
                                                    } else if (searchField == 2) {
                                                        cout << "Enter Account ID to search: ";
                                                        cin >> searchId;
                                                        cin.ignore();
                                                        for (const auto& buyer : buyers) {
                                                            if (buyer.getId() == searchId) {
                                                                cout << "[Buyer]" << endl;
                                                                buyer.printInfo();
                                                                found = true;
                                                            }
                                                        }
                                                    } else {
                                                        cout << "Search by Address/Phone Number not implemented in demo." << endl;
                                                    }
                                                    if (!found) cout << "No buyer found." << endl;
                                                } else if (searchType == 2) {
                                                    // Seller search
                                                    if (searchField == 1) {
                                                        cout << "Enter name to search: ";
                                                        getline(cin, searchName);
                                                        for (const auto& seller : sellers) {
                                                            if (seller.getName() == searchName) {
                                                                cout << "[Seller]" << endl;
                                                                cout << "Seller ID: " << seller.getId() << endl;
                                                                cout << "Seller Name: " << seller.getName() << endl;
                                                                // Add more seller details here if needed
                                                                found = true;
                                                            }
                                                        }
                                                    } else if (searchField == 2) {
                                                        cout << "Enter Account ID to search: ";
                                                        cin >> searchId;
                                                        cin.ignore();
                                                        for (const auto& seller : sellers) {
                                                            if (seller.getId() == searchId) {
                                                                cout << "[Seller]" << endl;
                                                                cout << "Seller ID: " << seller.getId() << endl;
                                                                cout << "Seller Name: " << seller.getName() << endl;
                                                                // Add more seller details here if needed
                                                                found = true;
                                                            }
                                                        }
                                                    } else {
                                                        cout << "Search by Address/Phone Number not implemented in demo." << endl;
                                                    }
                                                    if (!found) cout << "No seller found." << endl;
                                                } else {
                                                    cout << "Invalid type." << endl;
                                                }
                                                break;
                                            case 5:
                                                cout << "Which type you want to create?" << endl;
                                                cout << "1. Buyer" << endl;
                                                cout << "2. Seller" << endl;
                                                cout << "3. Bank Account" << endl;
                                                cin >> createType;
                                                cin.ignore();
                                                if (createType == 1) {
                                                    // Create Buyer
                                                    int newId = buyers.empty() ? 1 : buyers.back().getId() + 1;
                                                    cout << "Enter Buyer Name: ";
                                                    getline(cin, name);
                                                    buyers.emplace_back(newId, name, 0.0);
                                                    cout << "Buyer created with ID: " << newId << endl;
                                                } else if (createType == 2) {
                                                    // Create Seller
                                                    int newId = sellers.empty() ? 1 : sellers.back().getId() + 1;
                                                    cout << "Enter Seller Name: ";
                                                    getline(cin, name);
                                                    sellers.emplace_back(newId, name);
                                                    cout << "Seller created with ID: " << newId << endl;
                                                } else if (createType == 3) {
                                                    // Create Bank Account
                                                    int newId = buyers.empty() ? 1 : buyers.back().getId() + 1;
                                                    cout << "Enter Bank Customer Name: ";
                                                    getline(cin, name);
                                                    buyers.emplace_back(newId, name, 0.0);
                                                    cout << "Bank account created for customer with ID: " << newId << endl;
                                                } else {
                                                    cout << "Invalid type." << endl;
                                                }
                                                break;
                                            case 6:
                                                cout << "Remove (1) Buyer or (2) Seller by ID? ";
                                                cin >> removeType;
                                                cin.ignore();
                                                if (removeType == 1) {
                                                    cout << "Enter Buyer ID to remove: ";
                                                    cin >> bid;
                                                    cin.ignore();
                                                    found = false;
                                                    for (auto it = buyers.begin(); it != buyers.end(); ++it) {
                                                        if (it->getId() == bid) {
                                                            cout << "Are you sure you want to remove Buyer '" << it->getName() << "' (ID: " << bid << ")? (y/n): ";
                                                            cin >> confirm;
                                                            cin.ignore();
                                                            if (confirm == 'y' || confirm == 'Y') {
                                                                buyers.erase(it);
                                                                cout << "Buyer removed." << endl;
                                                            } else {
                                                                cout << "Operation cancelled." << endl;
                                                            }
                                                            found = true;
                                                            break;
                                                        }
                                                    }
                                                    if (!found) cout << "Buyer not found." << endl;
                                                } else if (removeType == 2) {
                                                    cout << "Enter Seller ID to remove: ";
                                                    cin >> sid;
                                                    cin.ignore();
                                                    found = false;
                                                    for (auto it = sellers.begin(); it != sellers.end(); ++it) {
                                                        if (it->getId() == sid) {
                                                            cout << "Are you sure you want to remove Seller '" << it->getName() << "' (ID: " << sid << ")? (y/n): ";
                                                            cin >> confirm;
                                                            cin.ignore();
                                                            if (confirm == 'y' || confirm == 'Y') {
                                                                sellers.erase(it);
                                                                cout << "Seller removed." << endl;
                                                            } else {
                                                                cout << "Operation cancelled." << endl;
                                                            }
                                                            found = true;
                                                            break;
                                                        }
                                                    }
                                                    if (!found) cout << "Seller not found." << endl;
                                                } else {
                                                    cout << "Invalid type." << endl;
                                                }
                                                break;
                                            case 7:
                                                accountMgmt = false;
                                                break;
                                            default:
                                                cout << "Invalid option." << endl;
                                                break;
                                        }
                                    }
                                }
                                break;
                            }
                            case 2: {
                                bool sysReport = true;
                                while (sysReport) {
                                    cout << "\nSystem Report:" << endl;
                                    cout << "1. Total number of Buyers" << endl;
                                    cout << "2. Total number of Sellers" << endl;
                                    cout << "3. Total number of Banking Accounts" << endl;
                                    cout << "4. Back" << endl;
                                    int repChoice;
                                    cin >> repChoice;
                                    switch (repChoice) {
                                        case 1:
                                            cout << "Total number of Buyers: " << buyers.size() << endl;
                                            break;
                                        case 2:
                                            cout << "Total number of Sellers: " << sellers.size() << endl;
                                            break;
                                        case 3:
                                            cout << "Total number of Banking Accounts: " << buyers.size() << endl;
                                            break;
                                        case 4:
                                            sysReport = false;
                                            break;
                                        default:
                                            cout << "Invalid option." << endl;
                                            break;
                                    }
                                }
                                break;
                            }
                            case 3:
                                cout << "Logging out of admin." << endl;
                                adminMenu = false;
                                admin_status = false;
                                prompt = LOGIN;
                                break;
                            default:
                                cout << "Invalid option." << endl;
                                break;
                        }
                    }
                } else {
                    cout << "Admin login failed." << endl;
                    prompt = LOGIN; // return to main menu if login failed
                    break;
                }
                break;
            default:
                cout << "Invalid option." << endl;
                break;
        }
        cout << endl;
    }

    //BankCustomer customer1(1, "Alice", 1000.0);
    //Buyer buyer1(1, customer1.getName(), customer1);
    return 1;
}