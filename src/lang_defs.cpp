#include "lang_defs.h"

const TextEditor::LanguageDefinition& SIDE_LANG::LanguageDefinition::Javascript() {
    static bool inited = false;
	static TextEditor::LanguageDefinition langDef;
	if (!inited)
	{
		static const char* const jsKeywords[] = {
            "break",
            "case",
            "catch",
            "continue",
            "debugger",
            "default",
            "delete",
            "do",
            "else",
            "finally",
            "for",
            "function",
            "if",
            "in",
            "instanceof",
            "new",
            "return",
            "switch",
            "this",
            "throw",
            "try",
            "typeof",
            "var",
            "void",
            "while",
            "with",
            "class",
            "const",
            "enum",
            "export",
            "extends",
            "import",
            "super",
            "implements",
            "interface",
            "let",
            "package",
            "private",
            "protected",
            "public",
            "static",
            "yield"
		};
		for (auto& k : jsKeywords)
			langDef.mKeywords.insert(k);

/*
		static const char* const identifiers[] = {
            
        };
		for (auto& k : identifiers)
		{
			TextEditor::Identifier id;
			id.mDeclaration = "Built-in function";
			langDef.mIdentifiers.insert(std::make_pair(std::string(k), id));
		}
		*/

		langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("L?\\\"(\\\\.|[^\\\"])*\\\"", TextEditor::PaletteIndex::String));
		langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("\\\'[^\\\']*\\\'", TextEditor::PaletteIndex::String));
		langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("0[xX][0-9a-fA-F]+[uU]?[lL]?[lL]?", TextEditor::PaletteIndex::Number));
		langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("[+-]?([0-9]+([.][0-9]*)?|[.][0-9]+)([eE][+-]?[0-9]+)?[fF]?", TextEditor::PaletteIndex::Number));
		langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("[+-]?[0-9]+[Uu]?[lL]?[lL]?", TextEditor::PaletteIndex::Number));
		langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("[a-zA-Z_][a-zA-Z0-9_]*", TextEditor::PaletteIndex::Identifier));
		langDef.mTokenRegexStrings.push_back(std::make_pair<std::string, TextEditor::PaletteIndex>("[\\[\\]\\{\\}\\!\\%\\^\\&\\*\\(\\)\\-\\+\\=\\~\\|\\<\\>\\?\\/\\;\\,\\.]", TextEditor::PaletteIndex::Punctuation));

		langDef.mCommentStart = "/*";
		langDef.mCommentEnd = "*/";
		langDef.mSingleLineComment = "//";

		langDef.mCaseSensitive = true;
		langDef.mAutoIndentation = true;

		langDef.mName = "Javascript";

		inited = true;
	}
	return langDef;
}