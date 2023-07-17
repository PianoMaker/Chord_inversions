#include "notes.h"
#include "Messages.h"


string choose_notation()
{
	if (lng) return choose_notation_uk;
	else return choose_notation_en;
}

string notationtypes()
{
	if (lng) return notationtypes_uk;
	else return notationtypes_en;
}

string choose_program()
{
	if (lng) return choose_program_uk;
	else return choose_program_en;
}

string choose_chords()
{
	if (lng) return choose_chords_uk;
	else return choose_chords_en;
}

string btw1and5()
{
	if (lng) return btw1and5_uk;
	else return btw1and5_en;
}

string choose_model()
{
	if (lng) return choose_model_uk;
	else return choose_model_en;
}

string all_voicings()
{
	if (lng) return all_voicings_uk;
	else return all_voicings_en;
}

string sp_voicings()
{
	if (lng) return sp_voicings_uk;
	else return sp_voicings_en;
}

string above()
{
	if (lng) return above_uk;
	else return above_en;
}

string aboveroot()
{
	if (lng) return aboveroot_uk;
	else return aboveroot_en;
}

string less()
{
	if (lng) return less_uk;
	else return less_en;
}

string more()
{
	if (lng) return more_uk;
	else return more_en;
}

string thank()
{
	if (lng) return thank_uk;
	else return thank_en;
}

string note_error()
{
	if (lng) return note_error_uk;
	else return note_error_en;
}

string trymore()
{
	if (lng) return trymore_uk;
	else return trymore_en;
}

string entertempo()
{
	if (lng) return entertempo_uk;
	else return entertempo_en;
}

string ndo()
{
	if (lng) return ndo_uk;
	else return ndo_en;
}

string nre()
{
	if (lng) return nre_uk;
	else return nre_en;
}

string nmi()
{
	if (lng) return nmi_uk;
	else return nmi_en;
}

string nfa()
{
	if (lng) return nfa_uk;
	else return nfa_en;
}

string nsol()
{
	if (lng) return nsol_uk;
	else return nsol_en;
}

string nla()
{
	if (lng) return nla_uk;
	else return nla_en;
}

string nsi()
{
	if (lng) return nsi_uk;
	else return nsi_en;
}

string enter()
{
	if (lng) return enter_uk;
	else return enter_en;
}

string sound()
{
	if (lng) return sound_uk;
	else return sound_en;
}

string fsounds()
{
	if (lng) return fsounds_uk;
	else return fsounds_en;
}

string melody()
{
	if (lng) return melody_uk;
	else return melody_en;
}

string root()
{
	if (lng) return root_uk;
	else return root_en;
}

string c7th()
{
	if (lng) return c7th_uk;
	else return c7th_en;
}

string i7th()
{
	if (lng) return i7th_uk;
	else return i7th_en;
}

string c9th()
{
	if (lng) return c9th_uk;
	else return c9th_en;
}
string c11th()
{
	if (lng) return c11th_uk;
	else return c11th_en;
}
string c13th()
{
	if (lng) return c13th_uk;
	else return c13th_en;
}

string chord_entered()
{
	if (lng) return chord_entered_uk;
	else return chord_entered_en;
}

string c_all()
{
	if (lng) return c_all_uk;
	else return c_all_en;
}
string c_chords()
{
	if (lng) return c_chords_uk;
	else return c_chords_en;
}

string c_chordswith()
{
	if (lng) return c_chordswith_uk;
	else return c_chordswith_en;
}

string in_melody()
{
	if (lng) return in_melody_uk;
	else return in_melody_en;
}

string save_as()
{
	if (lng) return save_as_uk;
	else return save_as_en;
}

string another()
{
	if (lng) return another_uk;
	else return another_en;
}

string chords_achieved()
{
	if (lng) return chords_achieved_uk;
	else return chords_achieved_en;
}

string upto12()
{
	if (lng) return upto12_uk;
	else return upto12_en;
}

string chords_containing()
{
	if (lng) return chords_containing_uk;
	else return chords_containing_en;
}

void tablestats()
{
	if (!lng)cout << "\nnumberofnotes \t" << "steps \t" << "chords possible \t";
	else cout << "\nкількість нот \t" << "ступені \t" << "акордів існує \t";
}

string choose_action()
{
	if (lng) return choose_action_uk;
	else return choose_action_en;
}

string display_only()
{
	if (lng) return display_only_uk;
	else return display_only_en;
}
string display_all()
{
	if (lng) return display_all_uk;
	else return display_all_en;
}
string display()
{
	if (lng) return display_uk;
	else return display_en;
}

string inversions_order()
{
	if (lng) return inversions_order_uk;
	else return inversions_order_en;
}

string range_order()
{
	if (lng) return range_order_uk;
	else return range_order_en;
}

string final_action()
{
	if (lng) return final_action_uk;
	else return final_action_en;
}

string inversions_root()
{
	if (lng) return inversions_root_uk;
	else return inversions_root_en;
}

string inversions_melody()
{
	if (lng) return inversions_melody_uk;
	else return inversions_melody_en;
}

string with_interval()
{
	if (lng) return with_interval_uk;
	else return with_interval_en;
}

string between()
{
	if (lng) return between_uk;
	else return between_en;
}

string chord_structure()
{
	if (lng) return chord_structure_uk;
	else return chord_structure_en;
}

string chord_choose()
{
	if (lng) return chord_choose_uk;
	else return chord_choose_en;
}

string chord_structure1()
{
	if (lng) return chord_structure1_uk;
	else return chord_structure1_en;
}
string chord_structure2()
{
	if (lng) return chord_structure2_uk;
	else return chord_structure2_en;
}
string chord_structure3()
{
	if (lng) return chord_structure3_uk;
	else return chord_structure3_en;
}

string tonetable()
{
	if (lng) return tonetable_uk;
	else return tonetable_en;
}

string ifsave()
{
	if (lng) return ifsave_uk;
	else return ifsave_en;
}

string intotal()
{
	if (lng) return intotal_uk;
	else return intotal_en;
}
string table_header()
{
	if (lng) return table_header_uk;
	else return table_header_en;
}

string use_eu()
{
	if (lng) return use_eu_uk;
	else return use_eu_en;
}

string use_us()
{
	if (lng) return use_us_uk;
	else return use_us_en;
}

string notes_eu()
{
	if (lng) return notes_eu_uk;
	else return notes_eu_en;
}

string notes_us()
{
	if (lng) return notes_us_uk;
	else return notes_us_en;
}

string increase_range_mel()
{
	if (lng) return increase_range_mel_uk;
	else return increase_range_mel_en;
}

string increase_range()
{
	if (lng) return increase_range_uk;
	else return increase_range_en;
}

string increase_range_root()
{
	if (lng) return increase_range_root_uk;
	else return increase_range_root_en;
}

string noentered()
{
	if (lng) return noentered_uk;
	else return noentered_en;
}

string anyway()
{
	if (lng) return anyway_uk;
	else return anyway_en;
}

string try_or_more()
{
	if (lng) return try_or_more_uk;
	else return try_or_more_en;
}

string chordmode()
{
	if (lng) return chordmode_uk;
	else return chordmode_en;
}