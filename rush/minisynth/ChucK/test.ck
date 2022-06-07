SinOsc osc => dac;
0.5 => osc.gain;
1000::ms => dur beat;

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
string track;

float tempo;
int count;

fun void ChangeNote(string note, float delay, float tempo)
{
	if (note == "a")
	{
		//<<< "note is",note>>>;	
		57 => Std.mtof => osc.freq;
		
	}
	if (note == "b")
	{
		//<<< "note is",note>>>;	
		59 => Std.mtof => osc.freq;
	}
	if (note == "c")
	{
		//<<< "note is",note>>>;	
		60 => Std.mtof => osc.freq;
	}
	if (note == "d")
	{
		//<<< "note is",note>>>;	
		62 => Std.mtof => osc.freq;
	}
	if (note == "e")
	{
		//<<< "note is",note>>>;	
		64 => Std.mtof => osc.freq;
	}
	if (note == "f")
	{
		//<<< "note is",note>>>;	
		65 => Std.mtof => osc.freq;
	}
	if (note == "g")
	{
		//<<< "note is",note>>>;	
		67 => Std.mtof => osc.freq;
	}
	if (note == "r")
	{
		//<<< "note is",note>>>;	
		0 => osc.freq;
	}

	//delay*0.5::second => now;
	delay*(60/tempo)::second => now;
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

string note;
int octave;
float delay;
for ( 0 => int i; i < notes.size(); i++)
{
    notes[i].find("/") => int index;
    notes[i].substring(index + 1).toFloat() => delay;
    notes[i].substring(0, 1) => note;
    if (index == 2)
    {
        notes[i].substring(1).toInt() => octave;
    }
	ChangeNote(note, delay, tempo);
    <<< note,octave,delay >>>;
}
