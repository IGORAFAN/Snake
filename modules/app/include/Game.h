#pragma once

class Game {
public:
	Game();
	~Game();
	void Start();
	void Stop();

private:
	bool isRunning_;
};
