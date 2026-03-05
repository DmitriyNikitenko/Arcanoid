# Arcanoid (SFML)

Простой клон арканоида на C++ и SFML.

## Зависимости

- **C++ компилятор** (Visual Studio / MSVC или любой совместимый)
- **SFML 3 (nightly / master)** или совместимая сборка, т.к. проект использует:
  - `sf::FloatRect::findIntersection`
  - `getGlobalBounds().size` у `sf::Text`

## Структура проекта

- `Arcanoid.vcxproj` – проект Visual Studio
- `*.cpp`, `include/*.h` – исходники игры
- `resources/` – игровые данные (уровни, текстуры, звуки, шрифты)

Убедитесь, что в папке `resources` лежат:

- `resources/fonts/karmatic_arcade.ttf`
- `resources/textures/background.png`
- `resources/textures/objects.png`
- `resources/textures/splashscreen.png`
- `resources/sounds/game-lost.wav`
- `resources/sounds/game-won.wav`
- `resources/sounds/next_level.wav`
- `resources/levels.txt`

Все эти файлы нужно добавить в репозиторий.

## Сборка и запуск (Windows / Visual Studio)

1. Установите SFML 3 (или подходящую dev-сборку) и пропишите пути к:
   - `SFML/include` в **VC++ Directories → Include Directories**
   - `SFML/lib` в **VC++ Directories → Library Directories**
2. Откройте `Arcanoid.vcxproj` в Visual Studio.
3. Соберите конфигурацию `Debug x64` или `Release x64`.
4. Убедитесь, что `*.dll` от SFML лежат в одной папке с `Arcanoid.exe` или в системном PATH.
5. Запустите игру из Visual Studio или напрямую `Arcanoid.exe`.

## Что коммитить

Рекомендуется **НЕ** коммитить файлы сборки (`x64/`, `Debug/`, `Release/`, `.vs/` и т.п.).  
В репозитории должны быть:

- исходники (`.cpp`, `.h`)
- файлы проекта (`.vcxproj`, `.filters`)
- папка `resources/` со всеми ассетами
- `.gitignore`
- `README.md`

