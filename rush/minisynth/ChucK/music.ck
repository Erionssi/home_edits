<<<"testing shit out">>>;

string filename;
// look at command line
if( me.args() > 0 ) me.arg(0) => filename;

// instantiate
FileIO fio;

// open a file
fio.open( filename, FileIO.READ );

// ensure it's ok
if( !fio.good() )
{
    cherr <= "can't open file: " <= filename <= " for reading..."
          <= IO.newline();
    me.exit();
}

// loop until end
string str;
string temp;

string notes[0];
float delay[0];
string tracks[0];

string track;

int tempo;
int count;

fun string ParseString(string notes[i])
{
	if (notes[i].substring(1) == )

}

while( fio => str )
{
    if (str == "tempo")
    {
        fio => str;
        str.toInt() => tempo;
    }
    if (str == "tracks")
    {
        fio => str;
        str => track;
    }
    str.find("/") => int check;
    if (check > 0)
    {
        notes << str.substring(0);
    }
}
for ( 0 => int i; i < notes.size(); i++)
{
    <<<  >>>;
}
