#include "Filepath.h"

namespace star
{
	Filepath::Filepath(const tstring & full_path)
		: m_Path(_T(""))
		, m_File(_T(""))
	{
		auto index = full_path.find_last_of('/');
		if(index == tstring::npos)
		{
			index = full_path.find_last_of('\\');
		}
		if(index != tstring::npos)
		{
			m_Path = full_path.substr(0,index);
			m_File = full_path.substr(index, full_path.length() - index);
		}
		else
		{
			m_File = full_path;
		}
	}

	Filepath::Filepath(const tstring & path, const tstring & file)
		: m_Path(path)
		, m_File(file)
	{

	}

	Filepath::Filepath(const Filepath & yRef)
		: m_Path(yRef.m_Path)
		, m_File(yRef.m_File)
	{
		
	}

	Filepath::~Filepath()
	{

	}

	const Filepath & Filepath::operator=(const Filepath & yRef)
	{
		m_Path = yRef.m_Path;
		m_File = yRef.m_File;
		return *this;
	}

	bool Filepath::operator==(const Filepath & yRef)
	{
		return m_Path == yRef.m_Path && m_File == yRef.m_File;
	}

	const tstring & Filepath::GetPath() const
	{
		return m_Path;
	}

	const tstring & Filepath::GetFile() const
	{
		return m_File;
	}

	tstring Filepath::GetName() const
	{
		tstring name(m_File);
		auto index(name.find_last_of(_T(".")));
		return name.substr(0, index);
	}

	tstring Filepath::GetExtension() const
	{
		tstring extension(m_File);
		auto index(extension.find_last_of(_T(".")));
		return extension.substr(index, extension.size() - index);
	}

	tstring Filepath::GetFullPath() const
	{
		return m_Path + m_File;
	}
}