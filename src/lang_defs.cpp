#include "lang_defs.h"

extern bool TokenizeCStyleString(const char * in_begin, const char * in_end, const char *& out_begin, const char *& out_end);
extern bool TokenizeCStyleCharacterLiteral(const char * in_begin, const char * in_end, const char *& out_begin, const char *& out_end);
extern bool TokenizeCStyleIdentifier(const char * in_begin, const char * in_end, const char *& out_begin, const char *& out_end);
extern bool TokenizeCStyleNumber(const char * in_begin, const char * in_end, const char *& out_begin, const char *& out_end);
extern bool TokenizeCStylePunctuation(const char * in_begin, const char * in_end, const char *& out_begin, const char *& out_end);

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

		static const char* const identifiers[] = {
            
        };
		for (auto& k : identifiers)
		{
			TextEditor::Identifier id;
			id.mDeclaration = "Built-in function";
			langDef.mIdentifiers.insert(std::make_pair(std::string(k), id));
		}

		langDef.mTokenize = [](const char * in_begin, const char * in_end, const char *& out_begin, const char *& out_end, TextEditor::PaletteIndex & paletteIndex) -> bool
		{
			paletteIndex = TextEditor::PaletteIndex::Max;

			while (in_begin < in_end && isascii(*in_begin) && isblank(*in_begin))
				in_begin++;

			if (in_begin == in_end)
			{
				out_begin = in_end;
				out_end = in_end;
				paletteIndex = TextEditor::PaletteIndex::Default;
			}
			else if (TokenizeCStyleString(in_begin, in_end, out_begin, out_end))
				paletteIndex = TextEditor::PaletteIndex::String;
			else if (TokenizeCStyleCharacterLiteral(in_begin, in_end, out_begin, out_end))
				paletteIndex = TextEditor::PaletteIndex::CharLiteral;
			else if (TokenizeCStyleIdentifier(in_begin, in_end, out_begin, out_end))
				paletteIndex = TextEditor::PaletteIndex::Identifier;
			else if (TokenizeCStyleNumber(in_begin, in_end, out_begin, out_end))
				paletteIndex = TextEditor::PaletteIndex::Number;
			else if (TokenizeCStylePunctuation(in_begin, in_end, out_begin, out_end))
				paletteIndex = TextEditor::PaletteIndex::Punctuation;

			return paletteIndex != TextEditor::PaletteIndex::Max;
		};

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