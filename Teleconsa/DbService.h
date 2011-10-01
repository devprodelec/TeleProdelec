#pragma once

using namespace System;
using namespace System::Collections;
using namespace System::Data::OleDb;

ref class DbService
{
	
private:
	OleDbConnection ^conn;
    OleDbCommand ^command;
    OleDbDataReader ^reader;

public:

	DbService();

	void testConnection();

	ArrayList^ listar();

	void insertar(String^ nombres, String^ apellidos, String^ telefono, String^ extension);

	void actualizar(int id, String^ nombres, String^ apellidos, String^ telefono, String^ extension);

	void eliminar(int id);
 
};
