/*
 * Proyecto hecho por Daniel Gutiérrez Gómez
 * A01068056.
 * Este es el documento de la clase CarRental
 * composición con inventario.
 *
 * Clase que hace manipulación de métodos de
 * clase Inventary.
 */
#ifndef CARRENTAL_H_
#define CARRENTAL_H_
#include <string>
#include <iostream>
#include "inventario.h" // Biblioteca con el objeto a usar
using namespace std;

// Declaración de clase CarRental
class CarRental
{
    // Variable privada de instancia
private:
    unsigned int id;

public:
    /*
     * Declaro métodos públicos y delcaro el apuntador de tipo Inventary acceder
     * a los métodos de Inventary con apuntadores y memoria dinámica.
     * También constructor por default.
     */
    Inventary *carInventary = new Inventary();
    CarRental() : id(0){};
    void showCarsInventary();
    void bookCars();
    void addCarsInventaryType();
    void addCarsInventary();
    void changePrice();
};

/**
 * Método que cambia de precios llamando
 * a método changePrices() de Inventary.
 *
 * @param
 * @return
 */
void CarRental::changePrice()
{
    carInventary->changePrices();
};

/**
 * Método que agrega carros a la empresa de renta de carros
 * llamando al método addCars() de Inventary.
 *
 * @param
 * @return
 */
void CarRental::addCarsInventary()
{
    carInventary->addCars();
};

/**
 * Método que agrega carros a la empresa por tipo de carro
 * si se ingresa suv, se 'construye' un Suv, si se ingresa
 * allTerrain, se construye un 'allTerrain' y si se ingresa
 * Luxury, se construye un Luxury, esto llamando a los mé-
 * todos correspondientes de Inventary.
 * Método que solo será usado si eres CEO del CarRental.
 *
 * @return
 * @param
 */
void CarRental::addCarsInventaryType()
{
    string type;
    string brand, color;
    float perform;
    unsigned int price;
    bool flag = true;
    cout << "Hola jefe, por favor escribe que tipo de carro deseas agregar al inventario: " << endl;
    cout << "suv, lujo o todoterreno: "
         << endl
         << endl;
    while (flag)
    {
        cin >> type;
        if (type == "suv")
        {
            cout << "Escribe una marca de SUV: " << endl;
            cin >> brand;
            cout << "Escribe el rendimiento del SUV: " << endl;
            cin >> perform;
            cout << "Escribe el color del SUV: " << endl;
            cin >> color;
            cout << "Escribe el price del SUV para su renta: " << endl;
            cin >> price;
            carInventary->constructSuv(brand, perform, color, price);
            flag = false;
            break;
        }
        if (type == "todoterreno")
        {
            cout << "Escribe una marca de todoTerreno: " << endl;
            cin >> brand;
            cout << "Escribe el rendimiento del todoTerreno: " << endl;
            cin >> perform;
            cout << "Escribe el color del todoTerreno: " << endl;
            cin >> color;
            cout << "Escribe el precio del todoTerreno para su renta: " << endl;
            cin >> price;
            carInventary->constructAllTerrain(brand, perform, color, price);
            flag = false;
            break;
        }
        if (type == "lujo")
        {
            cout << "Escribe una marca de lujo: " << endl;
            cin >> brand;
            cout << "Escribe el rendimiento del lujo: " << endl;
            cin >> perform;
            cout << "Escribe el color del lujo: " << endl;
            cin >> color;
            cout << "Escribe el precio del lujo para su renta: " << endl;
            cin >> price;
            carInventary->constructLuxury(brand, perform, color, price);
            flag = false;
            break;
        }
        else
        {
            cout << "Por favor escribe 'suv', 'lujo' o 'todoterreno': " << endl;
            flag = true;
        }
    }
};

/**
 *  Mostrar inventario actual de carros
 * llamando a método showCars() de Inventary
 *
 * @param
 * @return
 */
void CarRental::showCarsInventary()
{
    carInventary->showCars();
};

/**
 * Método para reservar carro
 * llamando a método de Inventary
 * showByPrice().
 * Nos enseña carros disponibles en
 * inventario y será utilizado en main()
 *
 * @param
 * @return void
 */
void CarRental::bookCars()
{
    bool flag = true;
    while (flag)
    {
        if (carInventary->showByPrice() == true)
        {
            flag = false;
            break;
        }
        else
        {
            cout << "No se encontró el carro que quieres. " << endl
                 << endl;
            flag = true;
            break;
        }
    }
};
#endif // CARRENTAL_H_
