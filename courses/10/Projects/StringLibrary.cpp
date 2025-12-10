#include <iostream>
#include <vector>
#include "../../libs/MyLib.h"
#include "../../libs/Date.h"
#include "../../libs/clsString.h"
using namespace Input;
using namespace Output;

using namespace std;



int main() {
    clsString String1;


    clsString String2("Mohammed");

    String1.Value = "Ali Ahmed";

   Printl( "String1 = " + String1.Value );
   Printl( "String2 = " + String2.Value );

   Printl("Number of words: " + String1.CountWords());

   Printl( "Number of words: " + String1.CountWords("Fadi ahmed rateb omer") );

   Printl( "Number of words: " + clsString::CountWords("Mohammed Saqer Abu-Hadhoud") );

    //----------------
    clsString String3("hi how are you?");

   Printl( "String 3 = " + String3.Value );

   Printl( "String Length = " + String3.Length() );

    String3.UpperFirstLetterOfEachWord();
    Printl( String3.Value );

    //----------------
    
    String3.LowerFirstLetterOfEachWord();
    Printl( String3.Value );

    //----------------

    String3.UpperAllString();
    Printl( String3.Value );

    //----------------

    String3.LowerAllString();
    Printl( String3.Value );

    //----------------

    Printl( "After inverting a : "  + clsString::InvertLetterCase('a') );

    //----------------

    String3.Value = "AbCdEfg";

    String3.InvertAllLettersCase();
   Printl( String3.Value );

    String3.InvertAllLettersCase();
   Printl( String3.Value );

    //----------------

   Printl( "Capital Letters count : "
        + clsString::CountLetters("Mohammed Abu-Hadhoud", clsString::CapitalLetters) );

    //----------------

    String3.Value = "Welcome to Jordan";
   Printl( String3.Value );

   Printl( "Capital Letters count :" + String3.CountCapitalLetters() );

    //----------------

   Printl( "Small Letters count :" + String3.CountSmallLetters() );

    //----------------

   Printl( "vowels count :" + String3.CountVowels() );

    //----------------

   Printl( "letter E count :" + String3.CountSpecificLetter('E', false) );

    //----------------

   Printl( "is letter u vowel? " + clsString::IsVowel('a')
        );

    //----------------

   Printl( "Words Count" + String3.CountWords()
        );

    //----------------


    vector<string> vString;

    vString = String3.Split(" ");

   Printl( "\nTokens = " + vString.size() );

    for (string& s : vString)
    {
       Printl( s );
    }

    //----------------

    //Tirms
    String3.Value = "    Mohammed Abu-Hahdoud     ";
   Printl( "\nString     = " + String3.Value );

    String3.Value = "    Mohammed Abu-Hahdoud     ";
    String3.TrimLeft();
   Printl( "\n\nTrim Left  = " + String3.Value);

    //----------------

    String3.Value = "    Mohammed Abu-Hahdoud     ";
    String3.TrimRight();
   Printl( "\nTrim Right = " + String3.Value);

    //----------------

    String3.Value = "    Mohammed Abu-Hahdoud     ";
    String3.Trim();
   Printl( "\nTrim       = " + String3.Value);

    //----------------

    //Joins
    vector<string> vString1 = { "Mohammed","Faid","Ali","Maher" };

   Printl( "\n\nJoin String From Vector: \n");
   Printl( clsString::JoinString(vString1, " "));


    string arrString[] = { "Mohammed","Faid","Ali","Maher" };

   Printl( "\n\nJoin String From array: \n");
   Printl( clsString::JoinString(arrString, 4, " "));

    //----------------

    String3.Value = "Mohammed Saqer Abu-Hahdoud";
   Printl( "\n\nString     = " + String3.Value);

    String3.ReverseWordsInString();
   Printl( "\nReverse Words : " + String3.Value
        );

    //---------------

    String3.Value = "Mohammed Saqer Abu-Hahdoud";
   Printl( "\nReplace : " + String3.FindAndReplace("Mohammed", "Sari")
        );

    //---------------

    String3.Value = "This is: a sample text, with punctuations.";
   Printl( "\n\nString     = " + String3.Value);

    String3.RemovePunctuations();
   Printl( "\nRemove Punctuations : " + String3.Value );


	return 0;

}