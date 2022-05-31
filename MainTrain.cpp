#include "Zoo.h"
#include "Mermaid.h"
#include "GoldFish.h"
#include "Horse.h"
#include "Flamingo.h"

//Train
int main()
{
	//section 1 - create a zoo and save to file output.txt
	Zoo z1( "Zoological Center Tel Aviv Ramat Gan Safari Israel", "1 Hatzvi Ave, Ramat Gan", 90, "8:00", "20:00" );

	z1.AddAnimal( new Horse( "GRAY", 2, 20, 11, 3, "Selle Francais" ) );
	z1.AddAnimal( new Mermaid( "BROWN", 3, 65.5, 9, 2, 2, 4, "Ariel", "Princess" ) );

	ofstream OutFile1( "output1.txt" );
	if( !OutFile1.is_open() )
	{
		cout << "Error opening output1.txt!\n";
		return 0;
	}

	OutFile1 << z1;
	OutFile1.close();

	//section 2 - create another zoo and use operators to add animals
	Zoo z2( "Hi Kef", "Rishon Le Ziyon", 40, "9:00", "21:00" );
	Flamingo* f1 = new Flamingo( "PINK", 1, 5.5, 2, 1.5 );
	z2 + f1;

	ofstream OutFile2( "output2.txt" );
	if( !OutFile2.is_open() )
	{
		cout << "Error opening output2.txt!\n";
		return 0;
	}

	OutFile2 << z2;
	OutFile2.close();

	//section 3 - use more operators
	Zoo z3 = z2 + z1;
	GoldFish* gf = new GoldFish( "GOLD", 5, 1, 3, 2, 100, 3, 0.3f, 0.7f );
	z3 += gf;

	ofstream OutFile3( "output3.dat", ios::out | ios::binary | ios::trunc );
	if( !OutFile3.is_open() )
	{
		cout << "Error opening output3.txt!\n";
		return 0;
	}

	z3.SaveBin( OutFile3 );
	OutFile3.close();

	//section 4 - load the zoo from the saved txt file
	Zoo z4;
	ifstream InFile1( "output1.txt" );

	if( !InFile1.is_open() )
	{
		cout << "Error opening output1.txt!\n";
		return 0;
	}

	InFile1 >> z4;
	InFile1.close();

	//section 5 - load the zoo from the saved txt file
	Zoo z5;
	ifstream InFile2( "output2.txt" );

	if( !InFile2.is_open() )
	{
		cout << "Error opening output2.txt!\n";
		return 0;
	}

	InFile2 >> z5;
	InFile2.close();

	//section 6 - load the zoo from the saved bin file
	ifstream InFile3( "output3.dat", ios::in | ios::binary );

	if( !InFile3.is_open() )
	{
		cout << "Error opening output3.txt!\n";
		return 0;
	}

	Zoo z6( InFile3 );
	InFile3.close();

	//now we test
	//part 1
	if( 0 != strcmp( z1.GetName(), z4.GetName() ) )
		cout << "Zoo name is wrong after loading from text file (-10)" << endl;

	if( 2 != z1.GetNumOfAnimals() )
		cout << "AddAnimal is wrong (-10)" << endl;

	Mermaid* m = dynamic_cast<Mermaid*>( z4.GetAnimals()[1] );
	if( 0 != strcmp( m->GetLastName(), "Princess" ) )
		cout << "Zoo name is wrong after loading from text file (-10)" << endl;

	//part 2
	if( 1 != z2.GetNumOfAnimals() )
		cout << "Animal count is wrong after adding another zoo (-10)" << endl;

	if( 5.5f != z5.GetAnimals()[0]->GetLifetime() )
		cout << "loading animals is wrong from text file (-10)" << endl;

	//part 3
	if( 0 != strcmp( z3.GetName(), "Hi Kef" ) )
		cout << "Zoo name is wrong after merging 2 zoos (-10)" << endl;

	if( 4 != z3.GetNumOfAnimals() )
		cout << "Zoo number of animals is wrong after merging 2 zoos (-10)" << endl;

	Flamingo* f2 = dynamic_cast<Flamingo*>( z3.GetAnimals()[0] );
	if( NULL == f2 )
		cout << "Zoo animals order is wrong after merging 2 zoos (-10)" << endl;

	if( 0 != strcmp( z6.GetOpenHour(), "9:00" ) )
		cout << "Zoo open hour is wrong after loading form bin file (-10)" << endl;

	Horse* h2 = dynamic_cast<Horse*>( z3.GetAnimals()[1] );
	if( NULL == h2 )
		cout << "Zoo animals order is wrong after loading from bin file (-10)" << endl;

	//finished
	cout << "done" << endl;

	return 0;
}