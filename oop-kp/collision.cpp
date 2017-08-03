#include "collision.h"

collision_state CircleTest(sf::Vector2f point, sf::Vector2f center, float radius)
{
	float dist2 = (point.x - center.x)*(point.x - center.x) + (point.y - center.y)*(point.y - center.y);
	float r2 = radius*radius;
	if (dist2 > r2)
		return collision_state::outside;
	else if (dist2 < r2)
		return collision_state::inside;
	else
		return collision_state::intersect;
}

collision_state BoundingBoxTest(sf::Vector2f point, sf::FloatRect rect)
{
	if (rect.contains(point))
		return collision_state::inside;
	else 
		return collision_state::outside;
}

collision_state BoundingBoxTest(sf::FloatRect rect1, sf::FloatRect rect2)
{
	if (rect2.intersects(rect1))
		return collision_state::intersect;
	else if (rect2.contains(sf::Vector2f(rect1.left, rect1.top)))
		return collision_state::inside;
	else
		return collision_state::outside;
}
