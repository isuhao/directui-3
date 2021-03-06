#ifndef __UIEDIT_H__
#define __UIEDIT_H__

#include <vector>

namespace DirectUICore 
{

//
// TODO: Try to add AutoComplete support
//

typedef enum 
{
	None = 0, Append, Suggest, SuggestAppend
} AutoCompleteMode;

class CEditWnd;

class UILIB_API CEditUI : public CLabelUI
{
    friend class CEditWnd;
public:
    CEditUI();

    LPCTSTR GetClass() const;
    LPVOID GetInterface(LPCTSTR pstrName);
    UINT GetControlFlags() const;

    void SetEnabled(bool bEnable = true);
    void SetText(LPCTSTR pstrText);
    void SetMaxChar(UINT uMax);
    UINT GetMaxChar();
    void SetReadOnly(bool bReadOnly);
    bool IsReadOnly() const;
    void SetPasswordMode(bool bPasswordMode);
    bool IsPasswordMode() const;
    void SetPasswordChar(TCHAR cPasswordChar);
    TCHAR GetPasswordChar() const;

	void SetAutoCompleteMode(AutoCompleteMode pAutoCompleteMode);
	AutoCompleteMode GetAutoCompleteMode() const;
	void SetAutoCompleteSource(std::vector<CStdString> pAutoCompleteSource);
	std::vector<CStdString> GetAutoCompleteSource();

    LPCTSTR GetNormalImage();
    void SetNormalImage(LPCTSTR pStrImage);
    LPCTSTR GetHotImage();
    void SetHotImage(LPCTSTR pStrImage);
    LPCTSTR GetFocusedImage();
    void SetFocusedImage(LPCTSTR pStrImage);
    LPCTSTR GetDisabledImage();
    void SetDisabledImage(LPCTSTR pStrImage);
    void SetNativeEditBkColor(DWORD dwBkColor);
    DWORD GetNativeEditBkColor() const;

    void SetSel(long nStartChar, long nEndChar);
    void SetSelAll();
    void SetReplaceSel(LPCTSTR lpszReplace);

    void SetPos(RECT rc);
    void SetVisible(bool bVisible = true);
    void SetInternVisible(bool bVisible = true);
    SIZE EstimateSize(SIZE szAvailable);
    void DoEvent(TEventUI& event);
    void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);

    void PaintStatusImage(HDC hDC);
    void PaintText(HDC hDC);

protected:
    CEditWnd* m_pWindow;

    UINT m_uMaxChar;
    bool m_bReadOnly;
    bool m_bPasswordMode;
    TCHAR m_cPasswordChar;
    UINT m_uButtonState;

	AutoCompleteMode m_pAutoCompleteMode;
	std::vector<CStdString> m_pAutoCompleteSource;

    CStdString m_sNormalImage;
    CStdString m_sHotImage;
    CStdString m_sFocusedImage;
    CStdString m_sDisabledImage;
    DWORD m_dwEditbkColor;
};

}

#endif // __UIEDIT_H__