
#ifndef CIMEDIT_INCLUDED
#define CIMEDIT_INCLUDED
#include <stdio.h>
#include <stdint.h>
#if defined _WIN32 || defined __CYGWIN__
    #ifdef CIMGUI_NO_EXPORT
        #define API
    #else
        #define API __declspec(dllexport) __attribute__((cdecl))
    #endif
#else
    #ifdef __GNUC__
        #define API  __attribute__((__visibility__("default")))
    #else
        #define API
    #endif
#endif

#if defined __cplusplus
    #define EXTERN extern "C"
#else
    #include <stdarg.h>
    #include <stdbool.h>
    #define EXTERN extern
#endif

#define CIMGUI_API EXTERN API


#ifdef CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#define NS 
#define CCONST
typedef struct TextEditor TextEditor;
typedef struct LanguageDefinition LanguageDefinition;
typedef struct Coordinates Coordinates;
struct Coordinates{
   int mLine, mColumn;
};
typedef enum SelectionMode
{
   Normal,
   Word,
   Line
}SelectionMode;
#else
#define NS TextEditor::
#endif

typedef enum ImEdit_Color
{
   ImEdit_Color_None,	
   ImEdit_Color_Keyword,// Keyword	
   ImEdit_Color_Number,	// Number
   ImEdit_Color_String,	// String
   ImEdit_Color_Literal, // Char literal
   ImEdit_Color_Punctuation, // Punctuation
   ImEdit_Color_Preprocessor,	// Preprocessor
   ImEdit_Color_Identifier, // Identifier
   ImEdit_Color_KnownIdentifier, // Known identifier
   ImEdit_Color_PreprocIdentifier, // Preproc identifier
   ImEdit_Color_CommentSingleLine, // Comment (single line)
   ImEdit_Color_CommentMultiLine, // Comment (multi line)
   ImEdit_Color_Background, // Background
   ImEdit_Color_Cursor, // Cursor
   ImEdit_Color_Selection, // Selection
   ImEdit_Color_ErrorMarker, // ErrorMarker
   ImEdit_Color_Breakpoint, // Breakpoint
   ImEdit_Color_LineNumber, // Line number
   ImEdit_Color_LineFill, // Current line fill
   ImEdit_Color_LineFillInactive, // Current line fill (inactive)
   ImEdit_Color_LineLineEdge, // Current line edge
   ImEdit_Color_Max,
}ImEdit_Color;

CIMGUI_API TextEditor* ImEdit_New();
CIMGUI_API void ImEdit_Delete(TextEditor* editor);
CIMGUI_API NS Coordinates ImEdit_GetCursorPosition(TextEditor* editor);
CIMGUI_API void ImEdit_SetText(TextEditor* e, char* text);
CIMGUI_API const char* ImEdit_GetText(TextEditor* e, NS Coordinates start, NS Coordinates end);
CIMGUI_API void ImEdit_SetReadOnly(TextEditor* e, bool value);
CIMGUI_API bool ImEdit_IsReadOnly(TextEditor* e);
CIMGUI_API bool ImEdit_IsTextChanged(TextEditor* e);
CIMGUI_API bool ImEdit_IsCursorPositionChanged(TextEditor* e);
CIMGUI_API bool ImEdit_IsColorizerEnabled(TextEditor* e);
CIMGUI_API void ImEdit_SetColorizerEnable(TextEditor* e, bool value);
CIMGUI_API void ImEdit_SetCursorPosition(TextEditor* e, NS Coordinates pos);
CIMGUI_API void ImEdit_SetHandleMouseInputs(TextEditor* e, bool value);
CIMGUI_API bool ImEdit_IsHandleMouseInputsEnabled(TextEditor* e);
CIMGUI_API void ImEdit_SetHandleKeyboardInputs(TextEditor* e, bool value);
CIMGUI_API bool ImEdit_IsHandleKeyboardInputsEnabled(TextEditor* e);
CIMGUI_API void ImEdit_SetImGuiChildIgnored(TextEditor* e, bool value);
CIMGUI_API bool ImEdit_IsImGuiChildIgnored(TextEditor* e);
CIMGUI_API void ImEdit_SetShowWhitespaces(TextEditor* e, bool value);
CIMGUI_API bool ImEdit_IsShowingWhitespaces(TextEditor* e);
CIMGUI_API void ImEdit_SetTabSize(TextEditor* e, int value);
CIMGUI_API int ImEdit_GetTabSize(TextEditor* e);
CIMGUI_API void ImEdit_InsertText(TextEditor* e, char* text);

CIMGUI_API void ImEdit_MoveUp(TextEditor* e, int aAmount,  bool aSelect);
CIMGUI_API void ImEdit_MoveDown(TextEditor* e, int aAmount, bool aSelect);
CIMGUI_API void ImEdit_MoveLeft(TextEditor* e, int aAmount, bool aSelect, bool aWordMode);
CIMGUI_API void ImEdit_MoveRight(TextEditor* e, int aAmount, bool aSelect, bool aWordMode);
CIMGUI_API void ImEdit_MoveTop(TextEditor* e, bool aSelect);
CIMGUI_API void ImEdit_MoveBottom(TextEditor* e, bool aSelect);
CIMGUI_API void ImEdit_MoveHome(TextEditor* e, bool aSelect);
CIMGUI_API void ImEdit_MoveEnd(TextEditor* e, bool aSelect);
CIMGUI_API void ImEdit_SetSelectionStart(TextEditor* e, NS Coordinates aPosition);
CIMGUI_API void ImEdit_SetSelectionEnd(TextEditor* e, NS Coordinates aPosition);
CIMGUI_API void ImEdit_SetSelection(TextEditor* e, NS Coordinates  aStart, NS Coordinates aEnd, NS SelectionMode aMode);

CIMGUI_API void ImEdit_SelectAll(TextEditor* e);
CIMGUI_API bool ImEdit_HasSelection(TextEditor* e);
CIMGUI_API void ImEdit_Copy(TextEditor* e);
CIMGUI_API void ImEdit_Cut(TextEditor* e);
CIMGUI_API void ImEdit_Paste(TextEditor* e);

CIMGUI_API bool ImEdit_IsOverwrite(TextEditor* e);
CIMGUI_API bool ImEdit_CanUndo(TextEditor* e);
CIMGUI_API bool ImEdit_CanRedo(TextEditor* e);
CIMGUI_API void ImEdit_Remove(TextEditor* e);

CIMGUI_API void ImEdit_Undo(TextEditor* e, int aSteps);
CIMGUI_API void ImEdit_Redo(TextEditor* e, int aSteps);

CIMGUI_API void ImEdit_Render(TextEditor* e, const char* aTitle, const ImVec2 aSize, bool aBorder);
CIMGUI_API NS LanguageDefinition* ImEdit_GetLanguageDefinition(TextEditor* e, char* name);
CIMGUI_API void ImEdit_ClearLanguageDefinitions();
CIMGUI_API void ImEdit_SetLanguageDefinition(TextEditor* e, NS LanguageDefinition* lang);
CIMGUI_API void ImEdit_AddPreprocIdentifiers(NS LanguageDefinition* lang,  char* name, char* value);
CIMGUI_API void ImEdit_ClearPreprocIdentifiers(NS LanguageDefinition* lang);
CIMGUI_API void ImEdit_AddIdentifiers(NS LanguageDefinition* lang,  char* name, char* value);
CIMGUI_API void ImEdit_ClearIdentifiers(NS LanguageDefinition* lang);
CIMGUI_API void ImEdit_AddKeywords(NS LanguageDefinition* lang,  char* name);
CIMGUI_API void ImEdit_ClearKeywords(NS LanguageDefinition* lang);
CIMGUI_API void ImEdit_AddErrorMarkers(TextEditor* e,  int line_number, char* error_info);
CIMGUI_API void ImEdit_ClearErrorMarkers(TextEditor* e);
CIMGUI_API void ImEdit_AddBreakpoint(TextEditor* e,  int line_number);
CIMGUI_API void ImEdit_ClearBreakpoint(TextEditor* e);
CIMGUI_API void ImEdit_SetComment(NS LanguageDefinition* lang, char* single_line_comment, char* comment_start, char* comment_end);
CIMGUI_API void ImEdit_AddRegEx(NS LanguageDefinition* lang,  char* regex, ImEdit_Color index);
CIMGUI_API void ImEdit_ClearRegEx(NS LanguageDefinition* lang);

CIMGUI_API void ImEdit_SetColor(TextEditor* e, ImEdit_Color index, ImU32 col);
CIMGUI_API ImU32 ImEdit_GetColor(TextEditor* e, ImEdit_Color index);



#undef NS
#endif
