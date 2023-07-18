#pragma once
using std::string;


bool ChooseLanguage();

const string choose_notation_uk = "Оберіть нотацію";
const string choose_notation_en = "Сhoose notation";
string choose_notation();

const string notationtypes_uk = "\n1 - класична європейська нотація\n2 - американська нотація\n";
const string notationtypes_en = "\n1 - classic european\n2 - modern american\n";
string notationtypes();

const string choose_program_uk = "\nОберіть програму\n";
const string choose_program_en = "\nChoose program\n";
string choose_program();

const string choose_chords_uk = "1 - Септакорди\n2 - Нонакорди\n3 - Ундецимакорди \n4 - Політерцієві із заданою кількістю звуків \n5 - статистика\n";
const string choose_chords_en = "1 - 7th chords\n2 - 9th chords \n3 - 11th chords \n4 - Extended with determined number of sounds \n5 - stats\n";
string choose_chords();

const string btw1and5_uk = "Оберіть від 1 до 5\n";
const string btw1and5_en = "Choose between 1 and 5\n";
string btw1and5();

const string choose_model_uk = "\n\nОберіть модель\n";
const string choose_model_en = "\n\nChoose model\n";
string choose_model();

const string all_voicings_uk = "0 - Шукати усі обернення та розташування\n";
const string all_voicings_en = "0 - Search all voicings\n";
string all_voicings();


const string sp_voicings_uk = "1 - Шукати лише розташування, в яких 9-, 11- і 13- тони";
const string sp_voicings_en = "1 - Search for voicing with 9th, 11th and 13th are more than octave ";
string sp_voicings();


const string above_uk = " вищі ";
const string above_en = " above ";
string above();

const string aboveroot_uk = "за основний тон щонайменш на нону - 1\n";
const string aboveroot_en = "the root \n";
string aboveroot();

const string entertempo_uk = "Введіть темп (20-500)\n";
const string entertempo_en = "Enter tempo (20-500)\n";
string entertempo();

const string less_uk = "число має бути менше ніж ";
const string less_en = "the number must be less than ";
string less();

const string more_uk = "число має бути більше ніж ";
const string more_en = "the number must be more than ";
string more();


const string thank_uk = "\nДякуємо за використання програми!";
const string thank_en = "\nThank you for using our program!";
string thank();


const string note_error_uk = "Помилка при введенні ноти ";
const string note_error_en = "Incorrect note ";
string note_error();


const string trymore_uk = "Спробуйте ще раз";
const string trymore_en = "Try once more";
string trymore();

const string ndo_uk = "до";
const string ndo_en = "do";
string ndo();


const string nre_uk = "ре";
const string nre_en = "re";
string nre();

const string nmi_uk = "мі";
const string nmi_en = "mi";
string nmi();

const string nfa_uk = "фа";
const string nfa_en = "fa";
string nfa();


const string nsol_uk = "соль";
const string nsol_en = "sol";
string nsol();


const string nla_uk = "ля";
const string nla_en = "la";
string nla();


const string nsi_uk = "сі";
const string nsi_en = "si";
string nsi();

const string enter_uk = "Введіть ";
const string enter_en = "Enter ";
string enter();

const string sound_uk = "\nзвук ";
const string sound_en = "\nsound ";
string sound();

const string fsounds_uk = " звуків";
const string fsounds_en = " sounds";
string fsounds();


const string melody_uk = "мелодичний тон\n";
const string melody_en = "melody\n";
string melody();

const string root_uk = "основний тон\n";
const string root_en = "root\n";
string root();

const string i7th_uk = "септим";
const string c7th_uk = "септ";
const string c9th_uk = "нон";
const string c11th_uk = "ундецим";
const string c13th_uk = "терцдецим";

const string i7th_en = "7th";
const string c7th_en = "7th";
const string c9th_en = "9th";
const string c11th_en = "11th";
const string c13th_en = "13th";

string c7th();
string i7th();
string c9th();
string c11th();
string c13th();


const string chord_entered_uk = "\nАкорд введено: ";
const string chord_entered_en = "\nChord entered: ";
string chord_entered();

const string c_all_uk = "\nУсі ";
const string c_all_en = "\nAll ";
string c_all();

const string c_chords_uk = "акорди";
const string c_chords_en = " chords";
string c_chords();

const string c_chordswith_uk = "акорди з ";
const string c_chordswith_en = " chords with ";
string c_chordswith();

const string in_melody_uk = "ою в мелодичному положенні";
const string in_melody_en = " in melody";
string in_melody();

const string save_as_uk = " Збережено у файлі ";
const string save_as_en = " Saved as ";
string save_as();

const string another_uk = "\nСпробувати інший акорд? 1 - так, 0 - продовжити роботу з цим акордом\n";
const string another_en = "\nTry another chord? 1 - yes, 0 - proceed with current chord\n";
string another();

const string chords_achieved_uk = "\nАкорди отримано:\n";
const string chords_achieved_en = "\nChords achieved:\n";
string chords_achieved();

const string upto12_uk = "кількість нот(до 12)\n";
const string upto12_en = "number of notes (up to 12)\n";
string upto12();


const string chords_containing_uk = "\nАкорди із ";
const string chords_containing_en = "\nChords containing ";
string chords_containing();

void tablestats();


const string choose_action_uk ="\nОберіть операцію";
const string choose_action_en = "\nChoose action";
string choose_action();


const string display_only_uk = "Вивести лише ";
const string display_all_uk = "Вивести усі ";
const string display_uk = "Вивести ";

const string display_only_en = "Display only ";
const string display_all_en = "Display all ";
const string display_en = "Display ";

string display_only();
string display_all();
string display();

const string inversions_order_uk = " в порядку обернень";
const string inversions_order_en = " in inversions order";
string inversions_order();

const string range_order_uk = " в порядку зростання діапазону";
const string range_order_en = " in ascending order of range";
string range_order();

const string final_action_uk = "\n1 - Зіграти акорди\n2 - Зберегти як текст\n3 - Зберегти як xml\n4 - Cпробувати інший акорд\n0 - завершення роботи\n";
const string final_action_en = "\n1 - Play chords\n2 - Save as text\n3 - Save as xml\n4 - Try another chord\n0 - Exit\n";
string final_action();

const string inversions_root_uk = " та обернення від заданої ноти";;
const string inversions_root_en = " and inversions from a given root";
string inversions_root();

const string inversions_melody_uk = " та обернення із заданим мелодичним тоном";
const string inversions_melody_en = " and inversions with a given melody tone";
string inversions_melody();

const string with_interval_uk = " з інтервалом ";
const string with_interval_en = " with ";
string with_interval();

const string between_uk = "и між крайніми голосами";
const string between_en = " between melody and root";
string between();

const string chord_choose_uk = "\nоберіть вид ";
const string chord_choose_en = "\nchoose ";
string chord_choose();

const string chord_structure_uk = "акорда: \n";
const string chord_structure_en = " chord structure: \n";
string chord_structure();


const string chord_structure1_uk = "1 - мажорний, 2 - домінантовий, 3 - мінорний, 4 - мажорний із секстою, 5 - збільшений, 0 - ввести вручну ";
const string chord_structure2_uk = "1 - мажорний, 2 - домінантовий, 3 - мінорний, 4 - мажорний із секстою, 5 - зменшений, 0 - ввести вручну ";
const string chord_structure3_uk = "1 - великий мажорний, 2 - малий мажорний, 3 - великий мінорний, 4 - малий мінорний, 5 - малий зменшений, 0 - ввести вручну ";


const string chord_structure1_en = "1 - major, 2 - dominant, 3 - minor, 4 - major 6/9, 5 - augmented, 0 - enter manually ";
const string chord_structure2_en = "1 - major, 2 - dominant, 3 - minor, 4 - major 6/9, 5 - diminished, 0 - enter manually ";
const string chord_structure3_en = "1 - major, 2 - dominant, 3 - minor major, 4 - minor, 5 - diminished, 0 - enter manually ";

string chord_structure1();
string chord_structure2();
string chord_structure3();


const string tonetable_uk = "\t\t\tЗвуки\t\t| діапазон\n \t\t\t\t\t|ступенів | півтонів\n";
const string tonetable_en = "\t\t\tPitches\t\t| range\n \t\t\t\t\t|degree | halftones\n";
string tonetable();

const string ifsave_uk = "\nЗберегти у файл? 1 - так, 2 - ні";
const string ifsave_en = "\nSave as file? 1 - yes, 2 - no";
string ifsave();


const string intotal_uk = "\nусього: ";
const string intotal_en = "\ntotal: ";
string intotal();

const string table_header_uk = "\t\t\tЗвуки\t\t| діапазон\n \t\t\t\t\t|ступенів / півтонів | консонансність | кв.коло ";
const string table_header_en = "\t\t\tTones\t\t| range\n \t\t\t\t\t|degrees / halftones | consonanse rate| sharpness ";
string table_header();

const string use_eu_uk = "\nДля введення нот використовуйте європейську буквенну нотацію:";
const string use_eu_en = "\nUse european traditional notation to enter notes:";
string use_eu();

const string use_us_uk = "\nДля введення нот використовуйте американську буквенну нотацію:";
const string use_us_en = "\nUse american scientific notation to enter notes:";
string use_us();

const string notes_eu_uk = "\nс - до, \td - ре, \te - мі, \nf - фа, \tg - соль, \ta - ля, \nb - сі-бемоль\th - сі \nis - дiєз, \tes - бемоль  \n";
const string notes_eu_en = "\nс - do, \td - re, \te - mi, \nf - fa, \tg - sol, \ta - la, \nb - si-b\th - si \nis - sharp, \tes - flat  \n";
string notes_eu();

const string notes_us_uk = "\nс - до, \td - ре, \te - мі, \nf - фа, \tg - соль, \ta - ля, \nb - сі \t#   - дiєз, \tb - бемоль  \n";
const string notes_us_en = "\n# - sharp, \tb - flat  \n";
string notes_us();

const string increase_range_uk = "акорди за зростанням діапазону";
const string increase_range_en = " chords by range increase";
string increase_range();

const string increase_range_mel_uk = "акорди за зростанням діапазону із заданим мелодичним тоном";
const string increase_range_mel_en = " chords by range increase with a given melody" ;
string increase_range_mel();

const string increase_range_root_uk = "акроди за зростанням діапазону від заданої ноти";
const string increase_range_root_en = " chords by range increase with a given root";
string increase_range_root();

const string noentered_uk = "введений акорд не є ";
const string noentered_en = "chord entered is not a ";
string noentered();

const string anyway_uk = "акордом. Все одно продовжити? \n";
const string anyway_en = " chord. Proceed anyway? \n";
string anyway();

const string try_or_more_uk = "1 - так, 2 - спробувати знову\n";
const string try_or_more_en = "1 - yes, 2 - try once more\n";
string try_or_more();

const string chordmode_uk = "1 - акорди, 2 - арпеджіо\n";
const string chordmode_en = "1 -chords, 2 - arpeggio\n";
string chordmode();
