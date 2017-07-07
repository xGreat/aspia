//
// PROJECT:         Aspia Remote Desktop
// FILE:            desktop_capture/desktop_rect.h
// LICENSE:         Mozilla Public License Version 2.0
// PROGRAMMERS:     Dmitry Chapyshev (dmitry@aspia.ru)
//

#ifndef _ASPIA_DESKTOP_CAPTURE__DESKTOP_RECT_H
#define _ASPIA_DESKTOP_CAPTURE__DESKTOP_RECT_H

#include "desktop_capture/desktop_size.h"
#include "desktop_capture/desktop_point.h"

namespace aspia {

class DesktopRect
{
public:
    DesktopRect() = default;
    DesktopRect(const DesktopRect& other);
    ~DesktopRect() = default;

    static DesktopRect MakeXYWH(int x, int y, int width, int height);
    static DesktopRect MakeWH(int width, int height);
    static DesktopRect MakeLTRB(int l, int t, int r, int b);
    static DesktopRect MakeSize(const DesktopSize& size);

    int Left() const;
    int Top() const;
    int Right() const;
    int Bottom() const;

    int x() const;
    int y() const;
    int Width() const;
    int Height() const;

    DesktopPoint LeftTop() const;

    bool IsEmpty() const;
    bool IsValid() const;

    bool IsEqual(const DesktopRect& other) const;
    DesktopSize Size() const;
    bool Contains(int x, int y) const;
    bool ContainsRect(const DesktopRect& other) const;
    void Translate(int dx, int dy);
    void IntersectWith(const DesktopRect& other);

    //
    // Enlarges current DesktopRect by subtracting |left_offset| and |top_offset|
    // from |left_| and |top_|, and adding |right_offset| and |bottom_offset| to
    // |right_| and |bottom_|. This function does not normalize the result, so
    // |left_| and |top_| may be less than zero or larger than |right_| and
    // |bottom_|.
    //
    void Extend(int left_offset, int top_offset, int right_offset, int bottom_offset);

    DesktopRect& operator=(const DesktopRect& other);

private:
    DesktopRect(int l, int t, int r, int b);

private:
    int32_t left_   = 0;
    int32_t top_    = 0;
    int32_t right_  = 0;
    int32_t bottom_ = 0;
};

} // namespace aspia

#endif // _ASPIA_DESKTOP_CAPTURE__DESKTOP_RECT_H
