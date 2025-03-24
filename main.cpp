#include <windows.h>
#include "nwpdlg.h"
#include "resource.h"

class main_dialog : public vsite::nwp::dialog
{
public:
    POINT position{};

protected:
    int idd() const override
    {
        return IDD_DIALOG1;
    }

    bool on_init_dialog() override
    {
        set_int(IDC_EDIT1, position.x);
        set_int(IDC_EDIT2, position.y);
        return true;
    }

    bool on_ok() override
    {
        try
        {
            position.x = get_int(IDC_EDIT1);
            position.y = get_int(IDC_EDIT2);
        }
        catch (...)
        {
            return false;
        }
        return true;
    }

    void on_cancel() override { }
};

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
    POINT cursorPos;
    GetCursorPos(&cursorPos);

    main_dialog dlg;
    dlg.position = cursorPos;

    if (dlg.do_modal(instance, 0) == IDOK)
    {
        SetCursorPos(dlg.position.x, dlg.position.y);
    }
    return 0;
}