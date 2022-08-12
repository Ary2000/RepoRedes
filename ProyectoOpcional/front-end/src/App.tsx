import React from 'react';
import { Home } from './Pages/Home';
import { Anfitrion } from './Pages/Anfitrion';
import { Invitado } from './Pages/Invitado';
import { BrowserRouter, Routes, Route } from 'react-router-dom'

function App() {
  return (
    <BrowserRouter>
      <Routes>
        <Route path="/" element={<Home/>}/>
        <Route path="anfitrion">
          <Route path =":idTablero" element={<Anfitrion/>}/>
        </Route>
        <Route path="invitado">
          <Route path =":idTablero" element={<Invitado/>}/>
        </Route>
      </Routes>
    </BrowserRouter>
  );
}

export default App;
