#include "Matrix3x3.h"

namespace defender
{
	const Matrix3x3 Matrix3x3::identity
	{
		Vector3{1, 0, 0}, 
		Vector3{0, 1, 0}, 
		Vector3{0, 0, 1}
	};
	
	const Matrix3x3 Matrix3x3::zero
	{ 
		Vector3{0, 0, 0}, 
		Vector3{0, 0, 0},
		Vector3{0, 0, 0},
	};

	inline Vector2 Matrix3x3::GetTranslation() const
	{
		return { rows[0][2], rows[1][2] };
	}

	inline float Matrix3x3::GetRotation() const
	{
		return std::atan2(rows[1][0], rows[0][0]);
	}

	inline Vector2 Matrix3x3::GetScale() const
	{
		Vector2 x = { rows[0][0], rows[0][1] };
		Vector2 y = { rows[1][0], rows[1][1] };

		return { x.Length(), y.Length() };
	}
}