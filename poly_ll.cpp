#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int coeff; // Coefficient
    int pow;   // Power
    Node* next;
};

// Function to create a new node
Node* createNode(int coeff, int pow, Node* next = nullptr) {
    Node* newNode = new Node();
    newNode->coeff = coeff;
    newNode->pow = pow;
    newNode->next = next;
    return newNode;
}

// Function to add two polynomials
Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = nullptr;
    Node** tail = &result;

    while (poly1 && poly2) {
        if (poly1->pow > poly2->pow) {
            *tail = createNode(poly1->coeff, poly1->pow);
            poly1 = poly1->next;
        } else if (poly1->pow < poly2->pow) {
            *tail = createNode(poly2->coeff, poly2->pow);
            poly2 = poly2->next;
        } else {
            *tail = createNode(poly1->coeff + poly2->coeff, poly1->pow);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        tail = &((*tail)->next);
    }

    while (poly1) {
        *tail = createNode(poly1->coeff, poly1->pow);
        poly1 = poly1->next;
        tail = &((*tail)->next);
    }

    while (poly2) {
        *tail = createNode(poly2->coeff, poly2->pow);
        poly2 = poly2->next;
        tail = &((*tail)->next);
    }

    return result;
}

// Function to multiply two polynomials
Node* multiplyPolynomials(Node* poly1, Node* poly2) {
    if (!poly1 || !poly2) return nullptr;

    Node* result = nullptr;

    for (Node* ptr1 = poly1; ptr1; ptr1 = ptr1->next) {
        Node* temp = nullptr;
        Node** tail = &temp;

        for (Node* ptr2 = poly2; ptr2; ptr2 = ptr2->next) {
            *tail = createNode(ptr1->coeff * ptr2->coeff, ptr1->pow + ptr2->pow);
            tail = &((*tail)->next);
        }

        result = addPolynomials(result, temp);
    }

    return result;
}

// Function to print a polynomial
void printPolynomial(Node* poly) {
    while (poly) {
        cout << poly->coeff << "x^" << poly->pow;
        poly = poly->next;
        if (poly) cout << " + ";
    }
    cout << endl;
}

// Main function
int main() {
    // Create first polynomial: 3x^3 + 2x^2 + 1
    Node* poly1 = createNode(3, 3, createNode(2, 2, createNode(1, 0)));

    // Create second polynomial: 4x^2 + 2x + 1
    Node* poly2 = createNode(4, 2, createNode(2, 1, createNode(1, 0)));

    cout << "Polynomial 1: ";
    printPolynomial(poly1);

    cout << "Polynomial 2: ";
    printPolynomial(poly2);

    // Add the polynomials
    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    printPolynomial(sum);

    // Multiply the polynomials
    Node* product = multiplyPolynomials(poly1, poly2);
    cout << "Product: ";
    printPolynomial(product);

    return 0;
}