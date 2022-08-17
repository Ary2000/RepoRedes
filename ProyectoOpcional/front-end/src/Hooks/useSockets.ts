import { useRef } from "react"
import io, { ManagerOptions, SocketOptions } from 'socket.io-client'

export const useSocket = (
    uri: string,
    opts?: Partial<ManagerOptions & SocketOptions> | undefined
) => {
    const { current: socket } = useRef(io(uri, opts))
}