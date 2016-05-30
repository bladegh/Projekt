// VorlageWindowsForm.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "Anmeldung.h"
#include "MyForm1.h"

using namespace VorlageWindowsForm;
using namespace System::Data::OleDb; 

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausführen


	


	//Erstelle Verbindung zur Datenbank
	String ^verbindung; 
	OleDbConnection^ dbVerbindung ; 
	verbindung="Provider = Microsoft.ACE.OLEDB.12.0; Data Source = H:\\Projekt\\WG_neu.accdb";
	dbVerbindung=gcnew OleDbConnection(verbindung);

	


	Application::Run(gcnew Anmeldung(dbVerbindung));

	//Application::Run(gcnew MyForm());
	


	return 0;
}
