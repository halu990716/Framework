#include "Tile.h"
#include "Bitmap.h"

Tile::Tile() : hor(0), ver(0)
{
}

Tile::~Tile()
{
}

void Tile::Start()
{
	transform.position = Vector3(0, 0);
	transform.scale = Vector3(SCALE_X, SCALE_Y);
	
	Option = 7;

	hor = 0;
	ver = 0;

}

int Tile::Update()
{
	POINT ptMouse;

	GetCursorPos(&ptMouse);

	ScreenToClient(g_hWnd, &ptMouse);

	/*float fx = ptMouse.x - transform.position.x;
	float fy = transform.position.y - ptMouse.y;

	float sum = transform.scale.x * 0.5f;

	float distanse = sqrt((fx * fx) + (fy * fy));*/

	if (transform.position.x - transform.scale.x * 0.5f < ptMouse.x &&
		transform.position.y - transform.scale.y * 0.5f < ptMouse.y &&
		ptMouse.x < transform.position.x + transform.scale.x * 0.5f &&
		ptMouse.y < transform.position.y + transform.scale.y * 0.5f)
	{
		if (GetAsyncKeyState(VK_LBUTTON))
		{
			hor = Option;

			if (hor >= 10)
			{
				// ** Áö·Ú.
				return 1;
			}
			//Sleep(100);
		}
	}
		if (GetAsyncKeyState(VK_TAB))
			hor = Option;
		return 0;
}

void Tile::Render(HDC hdc)
{
		TransparentBlt(hdc,
			int(transform.position.x - transform.scale.x * 0.5f),
			int(transform.position.y - transform.scale.y * 0.5f),
			(int)transform.scale.x,
			(int)transform.scale.y,
			(*ImageList)["Tile"]->GetMemDC(),
			int(transform.scale.x * hor),
			int(transform.scale.y * ver),
			(int)transform.scale.x,
			(int)transform.scale.y,
			RGB(255, 0, 255));
	//Sleep(1000);
}

void Tile::Destroy()
{
}
