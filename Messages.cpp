#include "notes.h"
#include "Messages.h"


string choose_notation(bool lang)
{
	if (lang) return choose_notation_uk;
	else return choose_notation_en;
}

string notationtypes(bool lang)
{
	if (lang) return notationtypes_uk;
	else return notationtypes_en;
}

string choose_program(bool lang)
{
	if (lang) return choose_program_uk;
	else return choose_program_en;
}

string choose_chords(bool lang)
{
	if (lang) return choose_chords_uk;
	else return choose_chords_en;
}

string btw1and5(bool lang)
{
	if (lang) return btw1and5_uk;
	else return btw1and5_en;
}

string choose_model(bool lang)
{
	if (lang) return choose_model_uk;
	else return choose_model_en;
}

string all_voicings(bool lang)
{
	if (lang) return all_voicings_uk;
	else return all_voicings_en;
}

string sp_voicings(bool lang)
{
	if (lang) return sp_voicings_uk;
	else return sp_voicings_en;
}

string above(bool lang)
{
	if (lang) return above_uk;
	else return above_en;
}

string aboveroot(bool lang)
{
	if (lang) return aboveroot_uk;
	else return aboveroot_en;
}

string less(bool lang)
{
	if (lang) return less_uk;
	else return less_en;
}

string thank(bool lang)
{
	if (lang) return thank_uk;
	else return thank_en;
}

string note_error(bool lang)
{
	if (lang) return note_error_uk;
	else return note_error_en;
}

string trymore(bool lang)
{
	if (lang) return trymore_uk;
	else return trymore_en;
}

string ndo(bool lang)
{
	if (lang) return ndo_uk;
	else return ndo_en;
}

string nre(bool lang)
{
	if (lang) return nre_uk;
	else return nre_en;
}

string nmi(bool lang)
{
	if (lang) return nmi_uk;
	else return nmi_en;
}

string nfa(bool lang)
{
	if (lang) return nfa_uk;
	else return nfa_en;
}

string nsol(bool lang)
{
	if (lang) return nsol_uk;
	else return nsol_en;
}

string nla(bool lang)
{
	if (lang) return nla_uk;
	else return nla_en;
}

string nsi(bool lang)
{
	if (lang) return nsi_uk;
	else return nsi_en;
}

string enter(bool lang)
{
	if (lang) return enter_uk;
	else return enter_en;
}

string sound(bool lang)
{
	if (lang) return sound_uk;
	else return sound_en;
}

string fsounds(bool lang)
{
	if (lang) return fsounds_uk;
	else return fsounds_en;
}

string melody(bool lang)
{
	if (lang) return melody_uk;
	else return melody_en;
}

string root(bool lang)
{
	if (lang) return root_uk;
	else return root_en;
}

string c7th(bool lang)
{
	if (lang) return c7th_uk;
	else return c7th_en;
}

string i7th(bool lang)
{
	if (lang) return i7th_uk;
	else return i7th_en;
}

string c9th(bool lang)
{
	if (lang) return c9th_uk;
	else return c9th_en;
}
string c11th(bool lang)
{
	if (lang) return c11th_uk;
	else return c11th_en;
}
string c13th(bool lang)
{
	if (lang) return c13th_uk;
	else return c13th_en;
}

string chord_entered(bool lang)
{
	if (lang) return chord_entered_uk;
	else return chord_entered_en;
}

string c_all(bool lang)
{
	if (lang) return c_all_uk;
	else return c_all_en;
}
string c_chords(bool lang)
{
	if (lang) return c_chords_uk;
	else return c_chords_en;
}

string c_chordsw(bool lang)
{
	if (lang) return c_chordsw_uk;
	else return c_chordsw_en;
}

string in_melody(bool lang)
{
	if (lang) return in_melody_uk;
	else return in_melody_en;
}

string save_as(bool lang)
{
	if (lang) return save_as_uk;
	else return save_as_en;
}

string another(bool lang)
{
	if (lang) return another_uk;
	else return another_en;
}

string chords_achieved(bool lang)
{
	if (lang) return chords_achieved_uk;
	else return chords_achieved_en;
}

string upto12(bool lang)
{
	if (lang) return upto12_uk;
	else return upto12_en;
}

string chords_containing(bool lang)
{
	if (lang) return chords_containing_uk;
	else return chords_containing_en;
}

void tablestats(bool lang)
{
	if (!lang)cout << "\nnumberofnotes \t" << "steps \t" << "chords possible \t";
	else cout << "\nкількість нот \t" << "ступені \t" << "акордів існує \t";
}

string choose_action(bool lang)
{
	if (lang) return choose_action_uk;
	else return choose_action_en;
}

string display_only(bool lang)
{
	if (lang) return display_only_uk;
	else return display_only_en;
}
string display_all(bool lang)
{
	if (lang) return display_all_uk;
	else return display_all_en;
}
string display(bool lang)
{
	if (lang) return display_uk;
	else return display_en;
}

string inversions_order(bool lang)
{
	if (lang) return inversions_order_uk;
	else return inversions_order_en;
}

string range_order(bool lang)
{
	if (lang) return range_order_uk;
	else return range_order_en;
}

string final_action(bool lang)
{
	if (lang) return final_action_uk;
	else return final_action_en;
}

string inversions_root(bool lang)
{
	if (lang) return inversions_root_uk;
	else return inversions_root_en;
}

string inversions_melody(bool lang)
{
	if (lang) return inversions_melody_uk;
	else return inversions_melody_en;
}

string with_interval(bool lang)
{
	if (lang) return with_interval_uk;
	else return with_interval_en;
}

string between(bool lang)
{
	if (lang) return between_uk;
	else return between_en;
}

string chord_structure(bool lang)
{
	if (lang) return chord_structure_uk;
	else return chord_structure_en;
}

string chord_choose(bool lang)
{
	if (lang) return chord_choose_uk;
	else return chord_choose_en;
}

string chord_structure1(bool lang)
{
	if (lang) return chord_structure1_uk;
	else return chord_structure1_en;
}
string chord_structure2(bool lang)
{
	if (lang) return chord_structure2_uk;
	else return chord_structure2_en;
}
string chord_structure3(bool lang)
{
	if (lang) return chord_structure3_uk;
	else return chord_structure3_en;
}

string tonetable(bool lang)
{
	if (lang) return tonetable_uk;
	else return tonetable_en;
}

string ifsave(bool lang)
{
	if (lang) return ifsave_uk;
	else return ifsave_en;
}
