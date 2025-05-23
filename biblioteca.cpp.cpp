#include <iostream>
#include <vector> //libreria para usar vectores dinamicos en vez de arreglos
#include <fstream> //libreria para generar e imprimir archivos
#include <ctime> //libreria para poder usar funciones de tiempo
using namespace std;

// motod independiente para registrar tiempo
void registrar() 
{
    ofstream fichero; // Declarar archivo
    fichero.open("registro.txt", ios::out); // Abrir fichero
    if (fichero.fail()) 
	{
        cout << "No se puede abrir el archivo" << endl;
        exit(1);
    }
    // Fichero es para marcar que se imprime en la ficha y cout en la consola
    fichero << "[Registro de consultas]" << endl;

    time_t tiempo_actual = std::time(nullptr);
    tm* tiempo_local = std::localtime(&tiempo_actual);

    // Imprimir la fecha
    fichero << "Fecha actual: " << endl;
    fichero << "Año actual: " << 1900 + tiempo_local->tm_year << endl;
    fichero << "Mes actual: " << 1 + tiempo_local->tm_mon << endl;
    fichero << "Día del mes: " << tiempo_local->tm_mday << endl;
    fichero.close();
    cout << "----------------------" << endl;
    cout << "Actualizacion de incio de sesion guardada" << endl;
}

class Libro 
{
private:
    string titulo;
    string autor;
    int anioPublicacion;
	bool status;
public:
    Libro(string titulo, string autor, int anioPublicacion, bool status) 
	{
        this->titulo = titulo;
		this->autor = autor;
		this->anioPublicacion = anioPublicacion;
		this->status = status;
    }
    
//getters y setters
    string getTitulo() const { return titulo; }
    void setTitulo(const string& newTitulo) { titulo = newTitulo; }
    
    string getAutor() const { return autor; }
    void setAutor(const string& newAutor) { autor = newAutor; }
    
    int getAnioPublicacion() const { return anioPublicacion; }
    void setAnioPublicacion(int newAnio) { anioPublicacion = newAnio; }
    
    bool getStatus() const { return status; }
    void setStatus(bool newStatus) { status = newStatus; }
// metodo para ver la informacion
    void mostrarInfo() const 
    {
        cout << "----------------------" << endl;
        cout << "Título del libro: " << titulo << endl;
        cout << "Autor del libro: " << autor << endl;
        cout << "Fecha de publicación del libro: " << anioPublicacion << endl;
        cout << "Estado del libro: " << (status ? "Disponible" : "No disponible") << endl;
        cout << "----------------------" << endl;
    }
    
// metodo para cambiar el status de los libros
    void alternarStatus() 
	{
	 status = !status; 
	}
};

class Biblioteca
{
private:
// Vector es como un arreglo pero crece o decrece según lo necesario
    vector<Libro> libros;
    
public:
// Método para agregar un libro
    void agregarLibro(const Libro& libro) 
	{ // const es para declarar variables como constantes, haciendo que su valor no se modifique después de inicializarla
        libros.push_back(libro); // push_back se usa para agregar datos a un vector
    }
// Método para mostrar todos los libros
    void mostrarLibros() const 
	{
        // For es un bucle para recorrer todos los datos
        for (const auto& libro : libros) 
		{
            libro.mostrarInfo();
            cout << "----------------------" << endl;
        }
    }
//metodo para buscar libros
    vector<Libro> buscarPorTitulo(const string& tituloBusqueda) const
    {
        vector<Libro> encontrados;
        for (const auto& libro : libros) 
        {
            if (libro.getTitulo() == tituloBusqueda) 
            {
                encontrados.push_back(libro);
            }
        }
        return encontrados;
    }

// metodo que permite cambiar el status por índice
    void cambiarStatusPorIndice(int indice, bool nuevoStatus)
    {
        if (indice >= 0 && indice < libros.size()) 
        {
            libros[indice].setStatus(nuevoStatus);
        }
    }

    int getNumLibros() const { return libros.size(); }
    Libro& getLibroPorIndice(int indice) { return libros.at(indice); }
};

int main()
{
    int menu;
    Biblioteca biblioteca;

// Crear libros
    Libro libro1("Cien años de soledad", "Gabriel García Márquez", 1967, true);
    Libro libro2("Don Quijote de la Mancha", "Miguel de Cervantes", 1605, false);

// Agregar libros a la biblioteca
    biblioteca.agregarLibro(libro1);
    biblioteca.agregarLibro(libro2);
    
// menu
    do
    {
        cout << "[---Biblioteca Municipal---]" << endl;
        cout << "[1]---Consultar libros---" << endl;
        cout << "[2]---Agregar libros---" << endl;
        cout << "[3]---Buscar libro---" << endl;
        cout << "[4]---Cambiar status del libro---" << endl;
        cout << "[5]---Salir---" << endl;
        cin >> menu;
        cin.ignore();

        switch (menu)
        {
            case 1:
                cout << "Libros en la biblioteca:\n";
                biblioteca.mostrarLibros();
                break;
            case 2:
            {
				// Declarar variables locales para los datos del nuevo libro
			    string titulo, autor;
			    int anioPublicacion;
			    bool status = true;
			
			    // Pedir al usuario los datos del libro
			    cout << "----------------------" << endl;
			    cout << "Título del libro: ";
			    cin.ignore(); // Ignorar el carácter residual en el búfer (osea el espacio)
			    getline(cin, titulo); // Leer el título completo, incluyendo espacios
			
			    cout << "Autor del libro: ";
			    getline(cin, autor); // Leer el autor completo, incluyendo espacios
			
			    cout << "Año de publicación del libro: ";
			    cin >> anioPublicacion;
			
			    // Crear un nuevo objeto de tipo Libro
			    Libro nuevoLibro(titulo, autor, anioPublicacion, status);
			
			    // Agregar el libro a la biblioteca
			    biblioteca.agregarLibro(nuevoLibro);
			
			    cout << "Libro agregado exitosamente.\n";
			    cout << "----------------------" << endl;
			    break;
            }
            case 3:
            {
                string tituloBusqueda;
                cout << "Ingrese el título del libro a buscar: ";
                getline(cin, tituloBusqueda);

                vector<Libro> encontrados = biblioteca.buscarPorTitulo(tituloBusqueda);
                if (encontrados.empty())
                {
                    cout << "No se encontró ningún libro con ese título.\n";
                }
                else
                {
                    for (const auto& libro : encontrados)
                        libro.mostrarInfo();
                }
                break;
            }
            case 4:
            {
            	// recorre la bse guardada para visualiar a que libro se le aran cambios
                cout << "Elija el número de libro para cambiar el status:\n";
                for (int i = 0; i < biblioteca.getNumLibros(); ++i)
                {
                    cout << "[" << i + 1 << "] " << biblioteca.getLibroPorIndice(i).getTitulo() << endl;
                }
                
                // se realiza la seleccon del libro
                int lbr;
                cin >> lbr;
                cin.ignore();
                
				if (lbr >= 1 && lbr <= biblioteca.getNumLibros())
				{
				    Libro& libro = biblioteca.getLibroPorIndice(lbr - 1);
				    libro.alternarStatus(); // Alterna el status
				    cout << "Status cambiado exitosamente.\n";
				}
				else
				{
				    cout << "Opción inválida.\n";
				}
                
                break;
            }
            case 5:
                registrar();
                break;
            default:
                cout << "Opción inválida. Intenta de nuevo.\n";
                break;
        }
    } while (menu != 5);

    return 0;
}
