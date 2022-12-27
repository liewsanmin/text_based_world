import os
import openai
openai.api_key = os.getenv("OPENAI_API_KEY")

ai_name = "\nAI: "
player_name = "\nHuman: "
locations = ["Crash Site", "Alien City", "Portal"]

intro = "A virtual text-based game where the player crash landed into an alien world"
solve_prompt = "give the player a fun simple math puzzle to solve, make sure it's related to the theme. Do not give me the answer"
congratz_prompt = "If the player answers correctly, say 'congratulations', else don't say 'congratulations'"
crash_site_prompt = f"{intro}. The player is now in a crash site, {solve_prompt} {congratz_prompt}"
alien_city_prompt = f"{intro}. The player is now in an alien city, {solve_prompt} {congratz_prompt}"
portal_prompt = f"{intro}. The player is now in a portal to return home, {solve_prompt} {congratz_prompt}"
location_prompts = {
    "Crash Site" : crash_site_prompt, 
    "Alien City" : alien_city_prompt, 
    "Portal" : portal_prompt
    }

def solve_puzzle(prompt):
    game = ""
    game = prompt
    while True:
        try:
            game += ai_name
            response = openai.Completion.create(
                model="text-davinci-003",
                prompt=game,
                temperature=0.96,
                max_tokens=3700,
                top_p=1,
                frequency_penalty=0,
                presence_penalty=0.6,
                stop=["AI", "Human"]
                )
            ai_response = response.choices[0].text
            prompt = f"{ai_name}{ai_response}"
            game += response.choices[0].text
            print(prompt)
            if "congratulations" in (ai_response).lower():
                break
            print(player_name)
            player_response = input()
            game += f'{player_name}{player_response}'
        except Exception as e:
            print(f'Looks like the game crashed! {e}')

if __name__ == "__main__":
    print("Welcome to a virtual text-based game! You've crash landed on an alien world. In order to escape,\
 you'll need to solve puzzles before moving to the next location!")
    for location, prompt in location_prompts.items():
        print(f"\nYou are now in {location}!")
        solve_puzzle(location, prompt)
    print("You escaped the alien world and won the game!")