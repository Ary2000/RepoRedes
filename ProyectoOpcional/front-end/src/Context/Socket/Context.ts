import { Socket } from "socket.io-client";

export interface ISocketContextState {
    socket: Socket | undefined;
    uid: string;
    users: string[];
}

export const defaultSocketContextState: ISocketContextState = {
    socket: undefined,
    uid: '',
    users: []
};

export type defaultSocketContextState = 'update_socket' | 'update_uid' | 'update_';

export type TSOcketContextPayload = string | string[] | Socket;

// export interface ISocketContextActions {
//     type: TSocketContet
// }