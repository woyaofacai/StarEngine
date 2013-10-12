#include "SpriteAnimationManager.h"
#include "../Input/XMLFileParser.h"
#include "../Input/XMLContainer.h"

namespace star
{
	std::shared_ptr<SpriteAnimationManager> SpriteAnimationManager::m_pManager = nullptr;
	
	SpriteAnimationManager::~SpriteAnimationManager()
	{

	}

	void SpriteAnimationManager::AddSpritesheet(const Filepath & file)
	{
		XMLFileParser parser(file);
		XMLContainer container;
		parser.Read(container);
		
		tstring name = container.GetAttributes()[_T("name")];
		auto it = m_Spritesheets.find(name);
		bool isValid = it == m_Spritesheets.end();
		ASSERT(isValid, _T("This spritesheet already exists!"));
		if(isValid)
		{
			Spritesheet spritesheet(container);
			m_Spritesheets.insert(std::pair<tstring, Spritesheet>(name, spritesheet));
		}
	}

	const Spritesheet & 
		SpriteAnimationManager::GetSpritesheet(const tstring & name) const
	{
		auto it = m_Spritesheets.find(name);
		bool isValid = it != m_Spritesheets.end();
		ASSERT(isValid, _T("Couldn't find this spritesheet..."));
		return m_Spritesheets.at(name);
	}

	std::shared_ptr<SpriteAnimationManager> SpriteAnimationManager::GetInstance()
	{
		if(m_pManager == nullptr)
		{
			m_pManager = std::shared_ptr<SpriteAnimationManager>(new SpriteAnimationManager());
		}
		return m_pManager;
	}

	SpriteAnimationManager::SpriteAnimationManager()
		: m_Spritesheets()
	{

	}
}
