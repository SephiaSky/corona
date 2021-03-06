//////////////////////////////////////////////////////////////////////////////
//
// Copyright (C) 2018 Corona Labs Inc.
// Contact: support@coronalabs.com
//
// This file is part of the Corona game engine.
//
// Commercial License Usage
// Licensees holding valid commercial Corona licenses may use this file in
// accordance with the commercial license agreement between you and 
// Corona Labs Inc. For licensing terms and conditions please contact
// support@coronalabs.com or visit https://coronalabs.com/com-license
//
// GNU General Public License Usage
// Alternatively, this file may be used under the terms of the GNU General
// Public license version 3. The license is as published by the Free Software
// Foundation and appearing in the file LICENSE.GPL3 included in the packaging
// of this file. Please review the following information to ensure the GNU 
// General Public License requirements will
// be met: https://www.gnu.org/licenses/gpl-3.0.html
//
// For overview and more information on licensing please refer to README.md
//
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Core\Rtt_Build.h"
#include "Interop\RuntimeEnvironment.h"
#include "Interop\UI\MessageOnlyWindow.h"
#include "Rtt_Callback.h"
#include "Rtt_WinAudioPlayer.h"


namespace Rtt
{

WinAudioPlayer::WinAudioPlayer(Interop::RuntimeEnvironment& environment, const ResourceHandle<lua_State> & handle)
:	PlatformAudioPlayer( handle ),
	fSound(environment.GetMessageOnlyWindow())
{
	fCompletionCallbackPointer = nullptr;
	fSound.SetPlayer(this);
}

WinAudioPlayer::~WinAudioPlayer()
{
}

bool WinAudioPlayer::Load( const char* filePath )
{
	fSound.Load(filePath);

	return true;
}

void WinAudioPlayer::Play()
{
	fSound.Play();
}

void WinAudioPlayer::Stop()
{
	fSound.Stop();
}

void WinAudioPlayer::Pause()
{
	fSound.Pause();
}

void WinAudioPlayer::Resume()
{
	fSound.Resume();
}

void WinAudioPlayer::SetVolume( Rtt_Real volume )
{
	fSound.SetVolume(volume);
}

Rtt_Real WinAudioPlayer::GetVolume() const
{
	return (Rtt_Real)fSound.GetVolume();
}

void WinAudioPlayer::NotificationCallback()
{
	if (fCompletionCallbackPointer)
	{
		fCompletionCallbackPointer->Invoke();
	}
	else
	{
		PlatformAudioPlayer::NotificationCallback();
	}
}

}	// namespace Rtt
