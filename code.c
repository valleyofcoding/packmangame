#include <stdio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>

int main() {
	srand(time(NULL));
	al_init();
	al_init_primitives_addon();

	ALLEGRO_DISPLAY *display = al_create_display(1750, 900);
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / 60);
	al_start_timer(timer);
	al_install_keyboard();
	al_install_mouse();

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_timer_event_source(timer));

	ALLEGRO_EVENT ev;

	int px = 300, py = 300, pr = 20;
	int dx = 50, dy = 50, dr = 5;
	int rotation = 1;
	int velocity = 2;

	while (1) {


		al_wait_for_event(queue, &ev);

		al_clear_to_color(al_map_rgb(0, 0, 0));

		al_draw_filled_circle(dx, dy, dr, al_map_rgb(255, 0, 0));


		if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
			rotation = 1;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT) {
			rotation = 2;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_UP) {
			rotation = 3;
		}
		else if (ev.keyboard.keycode == ALLEGRO_KEY_DOWN) {
			rotation = 4;
		}


		if (rotation == 1) {
			al_draw_filled_pieslice(px += velocity, py, pr, 0.5, 5, al_map_rgb(255, 255, 0));
		}
		else if (rotation == 2) {
			al_draw_filled_pieslice(px -= velocity, py, pr, 3.7, 5, al_map_rgb(255, 255, 0));
		}
		else if (rotation == 3) {
			al_draw_filled_pieslice(px, py -= velocity, pr, 5.2, 5, al_map_rgb(255, 255, 0));
		}
		else if (rotation == 4) {
			al_draw_filled_pieslice(px, py += velocity, pr, 2.2, 5, al_map_rgb(255, 255, 0));
		}

		if (abs(dx - px) < pr && abs(dy - py) < pr) {
			dx = rand() % 1550 + 100;
			dy = rand() % 700 + 100;
			pr += 3;
			velocity += 1;
		}

		if (px + pr > 1750 || px - pr < 0 || py + pr > 900 || py - pr < 0) {
			system("pause");
		}

		al_flip_display();
	}
	system("pause");
	return 0;
}
