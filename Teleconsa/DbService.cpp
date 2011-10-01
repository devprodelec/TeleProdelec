#include "StdAfx.h"
#include "DbService.h"

using namespace System::Windows::Forms;

DbService::DbService(void)
{
	conn = gcnew OleDbConnection("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=teleconsa.mdb");
}

void DbService::testConnection()
{
    try
    {
        conn->Open();
		command = gcnew OleDbCommand("SELECT * FROM usuarios", conn);
        reader = command->ExecuteReader();
        while (reader->Read())
        {
            ArrayList^ row = gcnew ArrayList;
            for (int i = 0; i < reader->FieldCount; i++)
            {
                row->Add(reader->GetValue(i));
            }
			MessageBox::Show(String::Format("Usuario: {0} {1} {2} {3}", row[0], row[1], row[2], row[3]));
        }
        reader->Close();
        conn->Close();
    }
    catch (OleDbException ^exc)
    {
        MessageBox::Show(String::Format("Error: {0}", exc));
		reader->Close();
        conn->Close();
    }
}

ArrayList^ DbService::listarCrud()
{
    ArrayList^ result = gcnew ArrayList;
    
    try
    {
        conn->Open();
		command = gcnew OleDbCommand("SELECT * FROM usuarios", conn);
        reader = command->ExecuteReader();

        while (reader->Read())
        {
            cli::array<String^, 1> ^row = gcnew cli::array<String^, 1>(5);
            for (int i = 0; i < reader->FieldCount; i++)
            {
				row->SetValue(String::Format("{0}", reader->GetValue(i)), i);

				//MessageBox::Show(String::Format("{0}", row->GetValue(i)));
            }
			
            result->Add(row);
        }
        reader->Close();
        conn->Close();
    }
    catch (OleDbException ^exc)
    {
        MessageBox::Show(String::Format("Error: {0}", exc));
		reader->Close();
        conn->Close();
    }

	return result;
}

ArrayList^ DbService::listarConf()
{
    ArrayList^ result = gcnew ArrayList;
    
    try
    {
        conn->Open();
		command = gcnew OleDbCommand("SELECT id, (nombres & \" \" & apellidos), telefono, extension FROM usuarios", conn);
        reader = command->ExecuteReader();

        while (reader->Read())
        {
            cli::array<String^, 1> ^row = gcnew cli::array<String^, 1>(4);
            for (int i = 0; i < reader->FieldCount; i++)
            {
				row->SetValue(String::Format("{0}", reader->GetValue(i)), i);

				//MessageBox::Show(String::Format("{0}", row->GetValue(i)));
            }
			
            result->Add(row);
        }
        reader->Close();
        conn->Close();
    }
    catch (OleDbException ^exc)
    {
        MessageBox::Show(String::Format("Error: {0}", exc));

		if (reader)
		{
			reader->Close();
		}

        conn->Close();
    }

	return result;
}

void DbService::insertar(String^ nombres, String^ apellidos, String^ telefono, String^ extension)
{
	try
    {
		String^ sql = String::Format("INSERT INTO usuarios (nombres,apellidos,telefono,extension) VALUES( " +
			"'{0}', '{1}','{2}','{3}') ", nombres, apellidos, telefono, extension);
        conn->Open();
		command = gcnew OleDbCommand(sql, conn);
		command->ExecuteNonQuery();
        
        conn->Close();
    }
    catch (OleDbException ^exc)
    {
        MessageBox::Show(String::Format("Error: {0}", exc));
        conn->Close();
    }
}


void DbService::actualizar(int id, String^ nombres, String^ apellidos, String^ telefono, String^ extension)
{
	try
    {
		String^ sql = String::Format("UPDATE usuarios SET " +
			"nombres = '{0}', " +
			"apellidos = '{1}', " + 
			"telefono = '{2}', " +
			"extension = '{3}' " +
			"WHERE id = {4}", nombres, apellidos, telefono, extension, id);
        conn->Open();
		command = gcnew OleDbCommand(sql, conn);
		command->ExecuteNonQuery();
        
        conn->Close();
    }
    catch (OleDbException ^exc)
    {
        MessageBox::Show(String::Format("Error: {0}", exc));
        conn->Close();
    }
}

void DbService::eliminar(int id)
{
	try
    {
        conn->Open();
		command = gcnew OleDbCommand(String::Format("DELETE FROM usuarios WHERE id = {0}", id), conn);
		command->ExecuteNonQuery();
        
        conn->Close();
    }
    catch (OleDbException ^exc)
    {
        MessageBox::Show(String::Format("Error: {0}", exc));
        conn->Close();
    }
}