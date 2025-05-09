#include <string>
#include <iostream>
using namespace std;


/*Don't Touch. Pag make ug copy if gusto ka mag edit


void AddProduct(){
}

void StockIn/StockOut(){
}

void SearchProduct(){
}

void DisplayAllProducts(){
}

void CalculateInventoryValue(){
}

void DeleteAProduct(){
}

void ExitSystem(){
}
*/


int main()
{
    int choices;
    
    do { //Diplay choices para kabalo ang user kung unsay kaya buhaton sa system
        cout << "UNSA IMONG GUSTO BUHATON? Select a number from 1-7\n";
        cout << "1. Add Product\n";
        cout << "2. Stock In/Stock Out\n";
        cout << "3. Search Product\n";
        cout << "4. Display All Products\n";
        cout << "5. Calculate Inventory Value\n";
        cout << "6. Delete a Product\n";        
        cout << "7. Exit System\n";        
        cout << "\nEnter Choices: ";
        cin >> choices;
                                        
    } while ( choices != 7); 
    
    
    // Don't Touch. Pag make ug copy if gusto ka mag edit
    
    /*switch(choices) {
        
        case 1: 
            AddProduct();
            break; 

        case 2: 
            StockIn/StockOut();
            break;

        case 3: 
            SearchProduct();
            break;
            
        case 4: 
            DisplayAllProducts();
            break;            

        case 5: 
            CalculateInventoryValue();
            break;

        case 6: 
            DeleteAProduct();
            break;
            
        case 7: 
            ExitSystem();
            break;   
            
        default: "Invalid Choice!"
        break;
    }*/
    
    
    return 0;
}