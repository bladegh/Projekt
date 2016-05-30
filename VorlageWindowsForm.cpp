// VorlageWindowsForm.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "Anmeldung.h"
#include "MyForm1.h"
#include "Dashboard.h"

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

	Anmeldung ^anmeldung = gcnew Anmeldung(dbVerbindung); 
	Application::Run(anmeldung);

	String ^login_name = anmeldung->get_login_Name();

	if(anmeldung->login_erfolgreich()==true)
	{
		Dashboard ^dash = gcnew Dashboard(login_name); 
		
		Application::Run(dash);

	}


	//Application::Run(anmeldung);
	//Application::Run(gcnew MyForm());
	


	return 0;
}
