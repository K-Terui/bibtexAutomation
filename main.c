// Abbreviation.abbreviationsに書かれた略語表に存在する略称を変換するプログラム
// 前置詞の消去も行う
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// 略語の対応表
struct Abbreviation {
    char original[256];
    char abbreviation[256];
};

struct Abbreviation abbreviations[] = {
    {"Abstracts", "Abstr."},
    {"Academy", "Acad."},
    {"Annals", "Ann."},
    {"Accelerator", "Accel."},
    {"Annual", "Annu."},
    {"Acoustics", "Acoust."},
    {"Apparatus", "App."},
    {"Active", "Act."},
    {"Applications", "Appl."},
    {"Administration", "Admin."},
    {"Applied", "Appl."},
    {"Administrative", "Administ."},
    {"Approximate", "Approx."},
    {"Advanced", "Adv."},
    {"Archive", "Arch."},
    {"Archives", "Arch."},
    {"Aeronautics", "Aeronaut."},
    {"Artificial", "Artif."},
    {"Aerospace", "Aerosp."},
    {"Assembly", "Assem."},
    {"Affective", "Affect."},
    {"Association", "Assoc."},
    {"Africa, African", "Afr."},
    {"Astronomy", "Astron."},
    {"Aircraft", "Aircr."},
    {"Astronautics", "Astronaut."},
    {"Algebraic", "Algebr."},
    {"Astrophysics", "Astrophys."},
    {"American", "Amer."},
    {"Atmosphere", "Atmos."},
    {"Atomic", "At."},
    {"Atoms", "At."},
    {"Broadcasting", "Broadcast."},
    {"Australasian", "Australas."},
    {"Bulletin", "Bull."},
    {"Australia", "Aust."},
    {"Bureau", "Bur."},
    {"Automatic", "Autom."},
    {"Business", "Bus."},
    {"Automation", "Automat."},
    {"Canadian", "Can."},
    {"Automotive", "Automot."},
    {"Ceramic", "Ceram."},
    {"Autonomous", "Auton."},
    {"Chemical", "Chem."},
    {"Behavior", "Behav."},
    {"Behavioral", "Behav."},
    {"Chinese", "Chin."},
    {"Belgian", "Belg."},
    {"Climatology", "Climatol."},
    {"Biochemical", "Biochem."},
    {"Clinical", "Clin."},
    {"Bioinformatics", "Bioinf."},
    {"Cognitive", "Cogn."},
    {"Biology, Biological", "Biol."},
    {"Colloquium", "Colloq."},
    {"Biomedical", "Biomed."},
    {"Communications", "Commun."},
    {"Biophysics", "Biophys."},
    {"Compatibility", "Compat."},
    {"British", "Brit."},
    {"Component", "Compon."},
    {"Components", "Compon."},
    {"Computational", "Comput."},
    {"Delivery", "Del."},
    {"Computer(s)", "Comput."},
    {"Department", "Dept."},
    {"Computing", "Comput."},
    {"Design", "Des."},
    {"Condensed", "Condens."},
    {"Detector", "Detect."},
    {"Conference", "Conf."},
    {"Development", "Develop."},
    {"Congress", "Congr."},
    {"Differential", "Differ."},
    {"Consumer", "Consum."},
    {"Digest", "Dig."},
    {"Conversion", "Convers."},
    {"Digital", "Digit."},
    {"Convention", "Conv."},
    {"Disclosure", "Discl."},
    {"Correspondence", "Corresp."},
    {"Discussions", "Discuss."},
    {"Critical", "Crit."},
    {"Dissertations", "Diss."},
    {"Crystal", "Cryst."},
    {"Distributed", "Distrib."},
    {"Crystallography", "Crystallogr."},
    {"Dynamics", "Dyn."},
    {"Cybernetics", "Cybern."},
    {"Earthquake", "Earthq."},
    {"Decision", "Decis."},
    {"Economic", "Econ."},
    {"Economics", "Econ."},
    {"Edition", "Ed."},
    {"Evolutionary", "Evol."},
    {"Education", "Educ."},
    {"Exhibition", "Exhib."},
    {"Electrical", "Elect."},
    {"Experimental", "Exp."},
    {"Electrification", "Electrific."},
    {"Exploratory", "Explor."},
    {"Electromagnetic", "Electromagn."},
    {"Exposition", "Expo."},
    {"Electroacoustic", "Electroacoust."},
    {"Express", "Express"},
    {"Electronic", "Electron."},
    {"Fabrication", "Fabr."},
    {"Emerging", "Emerg."},
    {"Faculty", "Fac."},
    {"Engineering", "Eng."},
    {"Ferroelectrics", "Ferroelect."},
    {"Environment", "Environ."},
    {"Francais, French", "Fr."},
    {"Equations", "Equ."},
    {"Frequency", "Freq."},
    {"Equipment", "Equip."},
    {"Foundation", "Found."},
    {"Ergonomics", "Ergonom."},
    {"Fundamental", "Fundam."},
    {"European", "Eur."},
    {"Generation", "Gener."},
    {"Evaluation", "Eval."},
    {"Geology", "Geol."},
    {"Geophysics", "Geophys."},
    {"Innovation", "Innov."},
    {"Geoscience", "Geosci."},
    {"Institute", "Inst."},
    {"Graphics", "Graph."},
    {"Instrument", "Instrum."},
    {"Guidance", "Guid."},
    {"Instrumentation", "Instrum."},
    {"Harmonic", "Harmon."},
    {"Harmonics", "Harmon."},
    {"Insulation", "Insul."},
    {"History", "Hist."},
    {"Integrated", "Integr."},
    {"Horizon", "Horiz."},
    {"Intelligence", "Intell."},
    {"Hungary, Hungarian", "Hung."},
    {"Intelligent", "Intell."},
    {"Hydraulics", "Hydraul."},
    {"Interactions", "Interact."},
    {"Hydrology", "Hydrol."},
    {"International", "Int."},
    {"Illuminating", "Illum."},
    {"Isotopes", "Isot."},
    {"Imaging", "Imag."},
    {"Israel", "Isr."},
    {"Industrial", "Ind."},
    {"Japan", "Jpn."},
    {"Information", "Inf."},
    {"Journal", "J."},
    {"Informatics", "Inform."},
    {"Knowledge", "Knowl."},
    {"Laboratory(ies)", "Lab."},
    {"Mathematical", "Math."},
    {"Language", "Lang."},
    {"Mathematics", "Math."},
    {"selected", "Sel."},
    {"Learning", "Learn."},
    {"Measurement", "Meas."},
    {"Letter", "Lett."},
    {"Letters", "Lett."},
    {"Mechanical", "Mech."},
    {"Lightwave", "Lightw."},
    {"Medical", "Med."},
    {"Logic", "Log."},
    {"Logical", "Log."},
    {"Metals", "Met."},
    {"Luminescence", "Lumin."},
    {"Metallurgy", "Metall."},
    {"Machine", "Mach."},
    {"Meteorology", "Meteorol."},
    {"Magazine", "Mag."},
    {"Metropolitan", "Metrop."},
    {"Magnetics", "Magn."},
    {"Mexican", "Mex."},
    {"Mexico", "Mex."},
    {"Management", "Manage."},
    {"Microelectromechanical", "Microelectromech."},
    {"Managing", "Manag."},
    {"Microgravity", "Microgr."},
    {"Manufacturing", "Manuf."},
    {"Microscopy", "Microsc."},
    {"Marine", "Mar."},
    {"Microwave(s)", "Microw."},
    {"Material", "Mater."},
    {"Military", "Mil."},
    {"Modeling", "Model."},
    {"Oceanic", "Ocean."},
    {"Molecular", "Mol."},
    {"Oceanography", "Oceanogr."},
    {"Monitoring", "Monit."},
    {"Occupation", "Occupat."},
    {"Multiphysics", "Multiphys."},
    {"Operational", "Oper."},
    {"Nanobioscience", "Nanobiosci."},
    {"Optical", "Opt."},
    {"Nanotechnology", "Nanotechnol."},
    {"Optics", "Opt."},
    {"National", "Nat."},
    {"Optimization", "Optim."},
    {"Naval", "Nav."},
    {"Organization", "Org."},
    {"Network", "Netw."},
    {"Networking", "Netw."},
    {"Packaging", "Packag."},
    {"Newsletter", "Newslett."},
    {"Particle", "Part."},
    {"Nondestructive", "Nondestruct."},
    {"Patent", "Pat."},
    {"Nuclear", "Nucl."},
    {"Performance", "Perform."},
    {"Numerical", "Numer."},
    {"Personal", "Pers."},
    {"Observations", "Observ."},
    {"Philosophical", "Philos."},
    {"Photonics", "Photon."},
    {"Productivity", "Productiv."},
    {"Photovoltaics", "Photovolt."},
    {"Programming", "Program."},
    {"Physics", "Phys."},
    {"Progress", "Prog."},
    {"Physiology", "Physiol."},
    {"Propagation", "Propag."},
    {"Planetary", "Planet."},
    {"Psychology", "Psychol."},
    {"Pneumatics", "Pneum."},
    {"Quality", "Qual."},
    {"Pollution", "Pollut."},
    {"Quarterly", "Quart."},
    {"Polymer", "Polym."},
    {"Radiation", "Radiat."},
    {"Polytechnic", "Polytech."},
    {"Radiology", "Radiol."},
    {"Practice", "Pract."},
    {"Reactor", "React."},
    {"Precision", "Precis."},
    {"Receivers", "Receiv."},
    {"Principles", "Princ."},
    {"Recognition", "Recognit."},
    {"Proceedings", "Proc."},
    {"Record", "Rec."},
    {"Processing", "Process."},
    {"Rehabilitation", "Rehabil."},
    {"Production", "Prod."},
    {"Reliability", "Rel."},
    {"Report", "Rep."},
    {"Semiconductor", "Semicond."},
    {"Research", "Res."},
    {"Sensing", "Sens."},
    {"Resonance", "Reson."},
    {"Series", "Ser."},
    {"Resources", "Resour."},
    {"Simulation", "Simul."},
    {"Review", "Rev."},
    {"Singapore", "Singap."},
    {"Robotics", "Robot."},
    {"Sistema", "Sist."},
    {"Royal", "Roy."},
    {"Society", "Soc."},
    {"Safety", "Saf."},
    {"Sociological", "Sociol."},
    {"Satellite", "Satell."},
    {"Software", "Softw."},
    {"Scandinavian", "Scand."},
    {"Solar", "Sol."},
    {"Science", "Sci."},
    {"Soviet", "Sov."},
    {"Section", "Sect."},
    {"Spectroscopy", "Spectrosc."},
    {"Security", "Secur."},
    {"Spectrum", "Spectr."},
    {"Seismology", "Seismol."},
    {"Speculations", "Specul."},
    {"Selected", "Sel."},
    {"Statistics", "Statist."},
    {"Structure", "Struct."},
    {"Terrestrial", "Terr."},
    {"Studies", "Stud."},
    {"Theoretical", "Theor."},
    {"Superconductivity", "Supercond."},
    {"Transactions", "Trans."},
    {"Supplement", "Suppl."},
    {"Translation", "Transl."},
    {"Surface", "Surf."},
    {"Transmission", "Transmiss."},
    {"Survey", "Surv."},
    {"Transportation", "Transp."},
    {"Sustainable", "Sustain."},
    {"Tutorials", "Tut."},
    {"Symposium", "Symp."},
    {"Ultrasonic", "Ultrason."},
    {"Systems", "Syst."},
    {"University", "Univ."},
    {"Technical", "Tech."},
    {"Vacuum", "Vac."},
    {"Techniques", "Techn."},
    {"Vehicular", "Veh."},
    {"Technology", "Technol."},
    {"Vibration", "Vib."},
    {"Telecommunications", "Telecommun."},
    {"Visual", "Vis."},
    {"Television", "Telev."},
    {"Welding", "Weld."},
    {"Temperature", "Temp."},
    {"Working", "Work."},
    //
    {"journal", "J."},
    {"Transactions", "Trans."},
    {"Conference", "Conf."}
};

// 大文字小文字を無視して略語を検索する関数
const char* findAbbreviation(const char* original) {
    int numAbbreviations = sizeof(abbreviations) / sizeof(abbreviations[0]);
    for (int i = 0; i < numAbbreviations; ++i) {
        if (strcasecmp(original, abbreviations[i].original) == 0) {
            return abbreviations[i].abbreviation;
        }
    }
    return original; // 見つからない場合は元の文字列を返す
}

// 前置詞を削除する関数
const char* removePrepositions(const char* input) {
    const char* prepositions[] = {"on", "in", "of"};
    const char replacement = ' ';

    // 入力文字列が前置詞かどうかをチェックし、前置詞であれば空文字列を返す
    for (int i = 0; i < sizeof(prepositions) / sizeof(prepositions[0]); i++) {
        if (strcmp(input, prepositions[i]) == 0) {
            return "";
        }
    }

    // 前置詞でない場合はそのままの入力文字列を返す
    return input;
}



int main() {
    char inputfilename[256];
    char outputfilename[256];

    printf("入力ファイル名を入力してください: ");
    scanf("%255s", inputfilename); // ファイル名は255文字以下と仮定して取得する
    printf("出力ファイル名を入力してください: ");
    scanf("%255s", outputfilename); // ファイル名は255文字以下と仮定して取得する
    FILE* inputFile = fopen(inputfilename, "r");
    // FILE* outputFile = fopen(outputfile, "w");

    // FILE* inputFile = fopen("sample.bib", "r");
    FILE* outputFile = fopen("temp.bib", "w");

    if (inputFile == NULL) {
        printf("入力ファイルを開けませんでした。\n");
        return 1;
    }

    if (outputFile == NULL) {
        printf("出力ファイルを開けませんでした。\n");
        fclose(inputFile);
        return 1;
    }

    char inputLine[1024];
    char* journalField;
    char* booktitleField;


    while (fgets(inputLine, sizeof(inputLine), inputFile)) {
        // 行にjournalフィールドが含まれているか確認する
        if ((journalField = strstr(inputLine, "journal={")) != NULL) {
            char* endBracket = strchr(journalField, '}');
            if (endBracket) {
                // journalフィールドの内容を取得
                char journalContent[1024];
                strncpy(journalContent, journalField + strlen("journal={"), endBracket - journalField - strlen("journal={"));
                journalContent[endBracket - journalField - strlen("journal={")] = '\0'; // ヌル文字で終端する

                // journalフィールドの内容を略語に変換して出力ファイルに書き込む
                char* token;
                const char* delimiters = " ,."; // スペースとカンマ、ピリオドを区切り文字として指定

                fprintf(outputFile, "  journal={");
                token = strtok(journalContent, delimiters);
                while (token != NULL) {
                    // printf("変換後の略語: %s\n", removePrepositions(findAbbreviation(token)));
                    fprintf(outputFile, "%s", removePrepositions(findAbbreviation(token)));
                    token = strtok(NULL, delimiters);
                    if (token != NULL) {
                        fprintf(outputFile, " "); // 略語の後にスペースを出力
                    }
                }
                fprintf(outputFile, "},\n");
            }
        } else if((booktitleField = strstr(inputLine, "booktitle={")) != NULL) { // 行にbooktitleフィールドが含まれているか確認する
            char* endBracket = strchr(booktitleField, '}');
            if (endBracket) {
                // booktitleフィールドの内容を取得
                char booktitleContent[1024];
                strncpy(booktitleContent, booktitleField + strlen("booktitle={"), endBracket - booktitleField - strlen("booktitle={"));
                booktitleContent[endBracket - booktitleField - strlen("booktitle={")] = '\0'; // ヌル文字で終端する

                // booktitleフィールドの内容を略語に変換して出力ファイルに書き込む
                char* token;
                const char* delimiters = " ,."; // スペースとカンマ、ピリオドを区切り文字として指定

                fprintf(outputFile, "  booktitle={");
                token = strtok(booktitleContent, delimiters);
                while (token != NULL) {
                    // printf("変換後の略語: %s\n", removePrepositions(findAbbreviation(token)));
                    fprintf(outputFile, "%s", removePrepositions(findAbbreviation(token)));
                    token = strtok(NULL, delimiters);
                    if (token != NULL) {
                        fprintf(outputFile, " "); // 略語の後にスペースを出力
                    }
                }
                fprintf(outputFile, "},\n");
            }
        } else {
            // journalフィールド以外の行はそのまま出力ファイルに書き込む
            fprintf(outputFile, "%s", inputLine);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    // 連続するスペースを削除
    const char* reinputFileName = "temp.bib";
    const char* reoutputFileName = outputfilename;

    FILE* reinputFile = fopen(reinputFileName, "r");
    if (reinputFile == NULL) {
        printf("Error: Cannot open the input file %s.\n", reinputFileName);
        return 1;
    }

    FILE* reoutputFile = fopen(reoutputFileName, "w");
    if (reoutputFile == NULL) {
        printf("Error: Cannot open the output file %s.\n", reoutputFileName);
        fclose(reinputFile);
        return 1;
    }

    int prevChar = ' ';
    int currentChar;

    while ((currentChar = fgetc(reinputFile)) != EOF) {
        if (!(prevChar == ' ' && currentChar == ' ')) {
            fputc(currentChar, reoutputFile);
        }
        prevChar = currentChar;
    }

    fclose(reinputFile);
    fclose(reoutputFile);
    remove("temp.bib");


    return 0;
}
